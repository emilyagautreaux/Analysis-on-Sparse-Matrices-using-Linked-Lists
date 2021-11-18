#pragma once
#include <iostream>

class Node {

public:

	~Node();
	Node(int row, int col, int val);
	friend class LinkedMatrix;

private:
	Node* next;
	int row;
	int col;
	int val;

};
