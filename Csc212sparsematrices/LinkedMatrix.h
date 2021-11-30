#pragma once
#include <iostream>
#include "Node.h"
#include <vector>


class LinkedMatrix {

private:

public:
	Node* head;
	LinkedMatrix();
	void append(int row, int col, int val);
	~LinkedMatrix();
	void print(Node* node, std::string type);
	std::vector<std::vector<int> > Linked2Vector(int m1rows, int m1cols, int m2rows, int m2cols, std::string type);
	void addMatrix(Node* m1, Node *m2);
	void subtractMatrix(Node* m1, Node* m2);
	void multiplyMatrix(Node* m1, Node* m2, int m1Rows, int m2Cols, int m1Cols);
	void inverseMatrix(Node* m1, int m1rows, int m1cols);
	int find(Node* m, int r, int c);
};

