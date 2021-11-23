#pragma once
#include <iostream>
#include "Node.h"


class LinkedMatrix {

private:

public:
	Node* head;
	LinkedMatrix();
	void append(int row, int col, int val);
	~LinkedMatrix();
	void print(Node* node);
	void addMatrix(Node* m1, Node *m2);
	void multiplyMatrix(Node* m1, Node* m2, int m1Rows, int m2Cols);
};

