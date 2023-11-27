#pragma once
#include <iostream>
#include<map>
#include<algorithm>
#include<string>
#include "Stack.h"
#include "Message.h"

using namespace std;

class Postfix {
	string infix;
	string postfix;
	void convert();
	bool has_var();
	bool infix_correct();
public:
	Postfix();
	Postfix(string);
	void load(string);
	double execute();
	map<char,double> get_var_map();
	double execute(map<char, double> vars);
	string get_infix() const;
	string get_postfix() const;
	friend ostream& operator<<(ostream&, Postfix&);
};
