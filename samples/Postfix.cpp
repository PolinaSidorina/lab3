#include "Postfix.h"

Postfix::Postfix() {
	infix = "";
	postfix = "";
}
Postfix::Postfix(string inf) {
	infix = inf;
	if (infix_correct()) convert();
	else throw invalid_argument("Incorrect");

}
bool Postfix::infix_correct() {
	string m;
	for (Message s : infix) {
		if (s.type() == MessageType::OPEN_BRACKET) m.push_back('0');
		if (s.type() == MessageType::CLOSE_BRACKET) m.push_back('1');
		if (s.type() == MessageType::OPERATOR) m.push_back('2');
		if (s.type() == MessageType::VARIABLE|| s.type() == MessageType::DIGIT) m.push_back('3');
	}
	if (m[0] == '2' || m[m.size() - 1] == '2') return false;
	for (string ex : {"22", "02", "33", "21", "10", "13", "30"}) {
		if (m.find("22") != -1) return false;
	}
	if (count(m.begin(), m.end(), '0') != count(m.begin(), m.end(), '1')) return false;
	return true;
}
void Postfix::convert() {
	postfix = "";
	Stack<Message> op;
	for (Message s : infix) {
		if (s.type() == MessageType::OPEN_BRACKET) op.push(s);
		if (s.type() == MessageType::CLOSE_BRACKET) {
			while (char(op.top()) != '(') postfix.push_back(op.pop());
			op.pop();
		}
		if (s.type() == MessageType::OPERATOR) {
			while (!(op.isEmpty()) && (s.prior() <= op.top().prior())) postfix.push_back(op.pop());
			op.push(s);
		}
		if (s.type() == MessageType::VARIABLE|| s.type() == MessageType::DIGIT) postfix.push_back(s);
		if (s.type() == MessageType::UNKNOW) 
			if(s!=' ') throw invalid_argument("error");
	}
	while (!op.isEmpty()) postfix.push_back(op.pop());
}
void Postfix::load(string s) {
	infix=s;
	if (infix_correct()) convert();
	else throw invalid_argument("error");
}
bool Postfix::has_var() {
	for (Message s : postfix) {
		if (s.type() == MessageType::VARIABLE) return true;
	}
	return false;
}
map<char, double> Postfix::get_var_map() {
	map<char, double> res;
	bool correct;
	string in;
	for (Message s : infix) {
		if (s.type() == MessageType::VARIABLE) res[s] = 0;
	}
	for (auto const& i_map : res) {
		correct = false;
		while (!correct) {
			cout << "Enter the value of" << i_map.first << " variable: ";
			cin >> in;
			try {
				res[i_map.first] = stod(in);
				correct = true;

			}
			catch (invalid_argument ignore) {
				cout << "Error" << endl;
			}
		}
	}
	return res;
}
double Postfix::execute() {
	if (has_var()) return execute(get_var_map());
	return execute({ {} });
}
double Postfix::execute(map<char, double> vars) {
	Stack<double> st;
	for (Message s : postfix) {
		if (s.type() == MessageType::DIGIT) st.push(s.to_int());
		if (s.type() == MessageType::VARIABLE) st.push(vars.at(s));
		if (s.type() == MessageType::OPERATOR) {
			double b = st.pop();
			double a = st.pop();
			if (s == '+') st.push(a + b);
			if (s == '-') st.push(a - b);
			if (s == '*') st.push(a * b);
			if (s == '/') st.push(a / b);
		}
	}
	return st.pop();
}
string Postfix::get_infix() const {
	return infix;
}
string Postfix::get_postfix() const {
	return postfix;
}
ostream& operator<<(ostream& ostr, Postfix& v) {
	cout << "Infix: " << v.infix << endl;
	cout << "Postfix: " << v.postfix << endl;
	return ostr;
}