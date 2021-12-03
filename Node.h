#pragma once
#include <iostream>

class Node {

public:
	Node* next;
	~Node();
	Node(int row, int col, int val);
	void deleteList(Node** head);
	friend class LinkedMatrix;

private:
	
	int row;
	int col;
	double val;

};
