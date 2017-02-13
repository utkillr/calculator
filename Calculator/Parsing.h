#include "calculator.h"
#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

/*

S -> M+S | M
M -> T*M | T
T -> N | (S)

M ::= T [+-M]. another:
M ::= T {+-T}*

*/

/*
	parse_m(Node* p) {
		if (p == NULL)
			t=parse_t();
		if (s[pos] == '-') {
			return parse_s(t);
	}

	parse_m() {
		t = parse_t();
		while(s[pos] == '-') {
			q = parse_t();
			t = new Node(t, q);
		}
	}

	parse_m(Node* prev) {
		if(s[pos] == '-') {
			parse_s(new Node(prev, parse_m(parse_t())));
		}
	}

*/

class Exception {
	int errorpos;
public:
	void complain() { printf ("Error at pos %d\n", errorpos); }
	Exception(int e): errorpos(e) {}
};

class Parse  {
	int pos;
public:
	char* s;
	Parse(char* _s) : s(_s), pos(0) {
	/*	int size = strlen(s);
		for (int i = 0; i<size; i++) {
			if (s[i] == ' ') {
				for (int j = i; j<size; j++) {
					s[j] = s[j+1];
				}
			}
		}*/
	};
	Node* parse_s();
	Node* parse_m();
	Node* parse_m(Node*);
	Node* parse_t();
	Node* parse_n();
};
/*
Node* Parse::parse_s() {
	Node* left = parse_m();
	char sym = s[pos];
	if (s[pos] == '+' || s[pos] == '-') {
		if (sym == '+') {
			pos++;
			Node* right = parse_s();
			return new Plus(left, right);
		}
		else {
			Node* right = new Num(0);
			while (s[pos] == '-') {
				pos++;
				right = new Minus(parse_t(), right);	
			}
		}
	}
	else return left;
}
*/
Node* Parse::parse_s() {
	Node* left = parse_m();
	char sym = s[pos];
	if (s[pos] == '+' || s[pos] == '-') {
		while (s[pos] == '+' || s[pos] == '-') {
			pos++;
			if (s[pos-1] == '+') left = new Plus(left, parse_m());
			else left = new Minus(left, parse_m());
		}
		return left;
	}
	else return left;

}
/*
Node* Parse::parse_m() {
	Node* left = parse_t();
	char sym = s[pos];
	if (s[pos] == '*' || s[pos] == '/') {
		pos++;
		Node* right = parse_m();
		if (sym == '*') return new Multy(left, right);
		else return new Divide(left, right);
	}
	else return left;
}
*/
Node* Parse::parse_m() {
	Node* left = parse_t();
	char sym = s[pos];
	if (s[pos] == '*' || s[pos] == '/') {
		while (s[pos] == '*' || s[pos] == '/') {
			pos++;
			if (s[pos-1] == '*') left = new Multy(left, parse_m());
			else left = new Divide(left, parse_m());
		}
		return left;
	}
	else return left;
}
Node* Parse::parse_t() {
	Node* next;
	if (s[pos] == '(') {
		pos++;
		next = parse_s();
		if (s[pos] != ')') throw new Exception(pos);
		else pos++;
	}
	else next = parse_n();
	return next;
}

Node* Parse:: parse_n() {
	bool numberExists = false;
	int number = 0;
	int step = pos;
	while (s[pos] >= '0' && s[pos] <= '9') {
		numberExists = true;
		number = number*10 + s[pos]-'0';
		pos++;
	}
	if (numberExists) return new Num(number);
	else throw new Exception(pos);
}

//