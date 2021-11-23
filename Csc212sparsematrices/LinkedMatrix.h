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
	void print(Node* node);
	std::vector<std::vector<int>> Linked2Vector(int rows, int cols);
	void addMatrix(Node* m1, Node *m2);
	void multiplyMatrix(Node* m1, Node* m2, int m1Rows, int m2Cols);
};

