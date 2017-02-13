#ifndef calc
#define calc

#include <iostream>
#include <stdio.h>
#include <math.h>
#include <vector>

using namespace std;

struct Node {
	virtual int compute() = 0;
	virtual void print() = 0;
	virtual Node* copy() = 0;
	//counter - spaces, flag - use them
	virtual void draw(int counter, bool flag) = 0;
	//if first
	virtual void draw() = 0;
	static int count;
	Node() { count++; }
	virtual ~Node() { count--; }
};

struct Num : Node {
	int n;
	int counter;
	Num(int _n) : n(_n), counter(0) {};
	virtual int compute() { return n; }
	virtual void print() { std::cout << n; }
	virtual Node * copy() { return new Num(n); }
	virtual void draw(int counter, bool flag);
	virtual void draw() { std::cout << n << endl; }
	~Num() { count--;}
};

/*Operands types*/

struct UnOp : Node {
	UnOp(Node* n) {
		next = n->copy();
	};
	Node* next;
	virtual Node* copy() = 0;
	virtual int compute() = 0;
	virtual void print() = 0;
	virtual void draw(int counte, bool flag) = 0;
	virtual void draw() = 0;
//	~UnOp() { delete next; }
};
struct BinOp : Node {
	BinOp(Node* l, Node* r) {
		left = l->copy();
		right = r->copy();
	};
	Node* right;
	Node* left;
	virtual Node* copy() = 0;
	virtual int compute() = 0;
	virtual void print() = 0;
	virtual void draw(int counte, bool flag) = 0;
	virtual void draw() = 0;
//	~BinOp() { delete right; delete left; }
};
struct TerOp : Node {
	TerOp(Node* l, Node* c, Node* r) {
		left = l->copy();
		center = c->copy();
		right = r->copy();
	};
	Node* right;
	Node* center;
	Node* left;
	virtual Node* copy() = 0;
	virtual int compute() = 0;
	virtual void print() = 0;
	virtual void draw(int counte, bool flag) = 0;
	virtual void draw() = 0;
//	~TerOp() { delete right; delete center; delete left; }
};

/*Operands (Un)*/

struct Inverse : UnOp {
	int counter;
	Inverse(Node* a) : UnOp(a) {};
	virtual Node* copy() { Inverse* a = new Inverse(*this); return a; }
	virtual int compute() { return next->compute() * (-1); }
	virtual void print();
	virtual void draw(int counter, bool flag);
	virtual void draw();
	~Inverse() { delete next; }
};
struct Ln : UnOp {
	Ln(Node* a) : UnOp(a) {};
	virtual Node* copy() { Ln* a = new Ln(*this); return a; }
	virtual int compute() { return (int)log(next->compute()); }
	virtual void print();
	virtual void draw(int counter, bool flag);
	virtual void draw();
	~Ln() { delete next; }
};

/*Operands (Bin)*/

struct Plus : BinOp {
	Plus(Node* a, Node* b) : BinOp(a, b) {};
	virtual Node* copy() { Plus* a = new Plus(*this); return a; }
	virtual int compute() { return left->compute() + right->compute(); }
	virtual void print();
	virtual void draw(int counter, bool flag);
	virtual void draw();
	~Plus() { delete right; delete left; }
};
struct Minus : BinOp {
	Minus(Node* a, Node* b) : BinOp(a, b) {};
	virtual Node* copy() { Minus* a = new Minus(*this); return a; }
	virtual int compute() { return left->compute() - right->compute(); }
	virtual void print();
	virtual void draw(int counter, bool flag);
	virtual void draw();
	~Minus() { delete right; delete left; }
};
struct Multy : BinOp {
	Multy(Node* a, Node* b) : BinOp(a, b) {};
	virtual Node* copy() { Multy* a = new Multy(*this); return a; }
	virtual int compute() { return left->compute() * right->compute(); }
	virtual void print();
	virtual void draw(int counter, bool flag);
	virtual void draw();
	~Multy() { delete right; delete left; }
};
struct Divide : BinOp {
	Divide(Node* a, Node* b) : BinOp(a, b) {};
	virtual Node* copy() { Divide* a = new Divide(*this); return a; }
	virtual int compute() { return left->compute() / right->compute(); }
	virtual void print();
	virtual void draw(int counter, bool flag);
	virtual void draw();
	~Divide() { delete right; delete left; }
};

/*Operands (Ter)*/

struct Ternary : TerOp {
	Ternary(Node* a, Node* b, Node* c) : TerOp(a, b, c) {};
	virtual Node* copy() { Ternary* a = new Ternary(*this); return a; }
	virtual int compute() { return left->compute() ? center->compute() : right->compute(); }
	virtual void print();
	virtual void draw(int counter, bool flag);
	virtual void draw();
	~Ternary() { delete right; delete center; delete left; }
};

/*Operands (arr) */

struct Max : Node {
	Max(vector<Node*> _a) : a(_a) {};
	vector<Node*> a;
	virtual Node* copy() { Max* a = new Max(*this); return a; }
	virtual int compute();
	virtual void print();
	virtual void draw(int counter, bool flag);
	virtual void draw();
	~Max() { for (int i = 0; i<a.size(); i++) delete a[i]; }
};

#endif