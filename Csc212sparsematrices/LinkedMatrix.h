
#pragma once
#include <iostream>
#include "Node.h"


class LinkedMatrix {

private:

public:
	Node* head;

	LinkedMatrix();
	void insert(int row, int col, int val);
	~LinkedMatrix();
	void print(Node* node);
	Node* gethead();
};

