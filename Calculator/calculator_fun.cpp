#include "calculator.h"
#include <math.h>
#include <string>
#include <iostream>

using namespace std;

void Num::draw(int counter, bool flag) {
	if (flag == true) for (int i = 1; i < counter; i++) std::cout << " ";
	std::cout << " " << n << endl;
}

/*Operands types*/

/*Operands (Un)*/

void Inverse::print() {
	std::cout << "( ";
	std::cout << '-';
	next->print();
	std::cout << " )";
}
void Inverse::draw(int counter, bool flag) {
	if (flag == true) for (int i = 1; i < counter; i++) std::cout << " ";
	std::cout << " -";
	next->draw(counter + 2, false);
	std::cout << endl;
}
void Inverse::draw() {
	std::cout << "-";
	next->draw(2, false);
	std::cout << endl;
}

void Ln::print() {
	std::cout << "ln(";
	next->print();
	std::cout << ')';
}
void Ln::draw(int counter, bool flag) {
	if (flag == true) for (int i = 1; i < counter; i++) std::cout << " ";
	std::cout << " ln";
	next->draw(counter + 3, false);
	std::cout << endl;
}
void Ln::draw() {
	std::cout << "ln";
	next->draw(3, false);
	std::cout << endl;
}

/*Operands (Bin)*/

void Plus::print() {
	std::cout << "( ";
	left->print();
	std::cout << " + ";
	right->print();
	std::cout << " )";
}
void Plus::draw(int counter, bool flag) {
	if (flag == true) for (int i = 1; i < counter; i++) std::cout << " ";
	std::cout << " +";
	left->draw(counter + 2, false);
	right->draw(counter + 2, true);
	std::cout << endl;
}
void Plus::draw() {
	std::cout << "+";
	left->draw(2, false);
	right->draw(2, true);
	std::cout << endl;
}

void Minus::print() {
	std::cout << "( ";
	left->print();
	std::cout << " - ";
	right->print();
	std::cout << " )";
}
void Minus::draw(int counter, bool flag) {
	if (flag == true) for (int i = 1; i < counter; i++) std::cout << " ";
	std::cout << " -";
	left->draw(counter + 2, false);
	right->draw(counter + 2, true);
	std::cout << endl;
}
void Minus::draw() {
	std::cout << "-";
	left->draw(2, false);
	right->draw(2, true);
	std::cout << endl;
}

void Multy::print() {
	left->print();
	std::cout << " * ";
	right->print();
}
void Multy::draw(int counter, bool flag) {
	if (flag == true) for (int i = 1; i < counter; i++) std::cout << " ";
	std::cout << " *";
	left->draw(counter + 2, false);
	right->draw(counter + 2, true);
	std::cout << endl;
}
void Multy::draw() {
	std::cout << "*";
	left->draw(2, false);
	right->draw(2, true);
	std::cout << endl;
}

void Divide::print() {
	left->print();
	std::cout << " / ";
	right->print();
}
void Divide::draw(int counter, bool flag) {
	if (flag == true) for (int i = 1; i < counter; i++) std::cout << " ";
	std::cout << " /";
	left->draw(counter + 2, false);
	right->draw(counter + 2, true);
	std::cout << endl;
}
void Divide::draw() {
	std::cout << "/";
	left->draw(2, false);
	right->draw(2, true);
	std::cout << endl;
}

/*Operands (Ter)*/

void Ternary::print() {
	std::cout << "( ";
	left->print();
	std::cout << " ? ";
	center->print();
	std::cout << " : ";
	right->print();
	std::cout << " )";
}
void Ternary::draw(int counter, bool flag) {
	if (flag == true) for (int i = 1; i < counter; i++) std::cout << " ";
	std::cout << "Ter";
	left->draw(counter + 4, false);
	center->draw(counter + 3, true);
	right->draw(counter + 3, true);
	std::cout << endl;
}
void Ternary::draw() {
	std::cout << "Ter";
	left->draw(4, false);
	center->draw(4, true);
	right->draw(4, true);
	std::cout << endl;
}

/*Operands (arr) */

int Max::compute() {
	int m = a[0]->compute();
	for (int i = 1; i<a.size(); i++) {
		int q = a[i]->compute();
		if (m<q) m=q;
	}
	return m;
}
void Max::print() {
	std::cout << "Max(";
	for (int i = 0; i<a.size()-1; i++) {
		a[i]->print();
		std::cout << ", ";
	}
	a[a.size()-1]->print();
	std::cout << ")";
}
void Max::draw(int counter, bool flag) {
	if (flag == true) for (int i = 1; i < counter; i++) std::cout << " ";
	std::cout << "Max";
	a[0]->draw(counter + 4, false);
	for (int i = 1; i<a.size(); i++) {
		a[i]->draw(counter + 4, true);
	}
}
void Max::draw() {
	std::cout << "Max";
	a[0]->draw(4, false);
	for (int i = 1; i<a.size(); i++) {
		a[i]->draw(4, true);
	}
}