#include "calculator.h"
#include <iostream>
#include <stdio.h>
#include <math.h>
#include "Parsing.h"

using namespace std;

int Node::count = 0;

int main() {
/*
	Node* a1 = new Multy(new Num(3), new Num(4));
	Node* a2 = new Plus(new Num(5), a1);
	Node* a3 = new Ln(a2);
	Node* a4 = new Inverse(new Num(3));
	Node* a5 = new Multy(new Num(5), new Num(6));
	Node* a6 = new Divide(new Num(10), new Num(2));
	Node* a7 = new Ternary(new Num(5), new Num(5), new Num(0));
	Node* a8 = new Plus(a4, a5);
	Node* a9 = new Plus(a8, a6);
	Node* a10 = new Minus(a9, a3);
	Node* a11 = new Plus(a10, a7);
	
	vector<Node*> arr;
	arr.push_back(a3->copy());
	arr.push_back(a11);
	arr.push_back(a2->copy());

	Node* res = new Max(arr);
*/


/*
	Node* m1 = new Ln(new Plus(new Num(5), new Multy(new Num(3), new Num(4))));
	Node* m2 = new Plus(new Minus(new Plus(new Plus(new Inverse(new Num(3)), new Multy(new Num(5), new Num(6))), new Divide(new Num(10), new Num(2))), new Ln(new Plus(new Num(5), new Multy(new Num(3), new Num(4))))), new Ternary(new Num(5), new Num(5), new Num(0)));
	Node* m3 = new Plus(new Num(5), new Multy(new Num(3), new Num(4)));

	vector<Node*> arr;
	arr.push_back(m1);
	arr.push_back(m2);
	arr.push_back(m3);
*/
	char* s = new char[];
	s = "5*(302-176)+5706/6";	//
	Parse p(s);
	Node* res = p.parse_s();

//	Node* ter = new Ternary(new Multy(new Num(2), new Num(3)), new Plus(new Num(1), new Num(3)), new Ternary(new Num(3), new Num(5), new Divide(new Num(12), new Num(3))));

//	Node* res = new Max(arr);

	res->print();
	cout << endl;
	res->draw();
	cout << endl;
	cout << res->compute() << endl;

//	ter->draw();
//	cout << endl << Node::count << endl;
	
//	delete ter;
/*	
	delete m1;
	delete m2;
	delete m3;
	cout << endl << Node::count << endl;
*/	
	delete res;
	return 0;
}

// make + - * / done!
// make print / done!
// tree draw (pseudograph) halfdone...
// make un. minus, log done!
// make a?b:c done!
// make maximum done!