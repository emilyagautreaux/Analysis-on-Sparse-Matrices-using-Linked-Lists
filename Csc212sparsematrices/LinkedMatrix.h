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
	void addMatrix(Node* m1, Node *m2, LinkedMatrix* m3);
	std::vector<std::vector<int>> Linked2Vector(int rows, int cols);
};

