
#include <iostream>
#include "LinkedMatrix.h"


//constructor
LinkedMatrix::LinkedMatrix() {
	head = NULL;
}
//deconstrucotr (idk if this will work, it needs testing) 
LinkedMatrix::~LinkedMatrix() {

	Node* current = head;
	while (current != NULL) {
		current = current->next;
		delete head;
		head = current;
	}
	head = NULL;
	
}

Node* LinkedMatrix::gethead() {


	return head;
}

// someone plz check this 
void LinkedMatrix::insert(int row, int col, int val) {
	
	Node* newNode = new Node(row, col, val);
	Node* temp = head;

	if (head == NULL)
		head = newNode;
	
	else {
		Node* temp = head;
		while (temp->next != NULL) {
			temp = temp->next;
		}

		temp->next = newNode;

	}

	
}


void LinkedMatrix::print(Node* node) {

	while (node != NULL) {

		std::cout << node->val << "->";
		node = node->next;
	}
	std::cout << "nullptr";
}

