#pragma once
enum class MessageType{OPEN_BRACKET,CLOSE_BRACKET,OPERATOR,DIGIT,VARIABLE,UNKNOW};
class Message {
	char sign;
public:
	Message(char _ = '0') {
		sign = _;
	}
	operator char() {
		return sign;
	}
	int to_int() {
		int a = (int)sign - '0';
		return a;
	}
	int prior() {
		if (sign == '/' || sign == '*') return 1;
		else if (sign == '-' || sign == '+') return 2;
		else return 3;
	}
	MessageType type() {
		string op = "+-*/";
		if (sign == '(') return MessageType::OPEN_BRACKET;
		else if (sign == ')') return MessageType::CLOSE_BRACKET;
		else if (op.find(sign) != -1) return MessageType::OPERATOR;
		else if (sign >= '0' && sign <= '9') return MessageType::DIGIT;
		else if ((sign >= 'a' && sign <= 'z') || (sign >= 'A' && sign <= 'Z')) return MessageType::VARIABLE;
		else return MessageType::UNKNOW;
	}
};