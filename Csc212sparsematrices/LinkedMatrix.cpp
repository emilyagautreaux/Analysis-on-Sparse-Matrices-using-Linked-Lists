#include <iostream>
#include<vector>
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
/// <function adds two linked lists together >

/// m1 = head of the first linked list
/// m2 = head of the second linked list
/// m3 = the 3rd linked list which holds the sums
void LinkedMatrix::addMatrix(Node* m1,Node* m2, LinkedMatrix* m3) {

	while (m1 != NULL && m2 != NULL) {

		// if both rows are equal 
		if (m1->row == m2->row) {

			// if columns are equal 
			if (m1->col == m2->col) {
				m3->append(m1->row, m1->col, m1->val + m2->val);
				m1 = m1->next;
				m2 = m2->next;
			}
			// m1 column being less than m2
			else {
				if (m1->col < m2->col) {
					m3->append(m1->row, m1->col, m1->val);
					m1 = m1->next;
				}
				// m2 column less than m1 
				else {
					m3->append(m2->row, m2->col, m2->val);
					m2 = m2->next;
				}
			}
		}
		// rows are not equal 
		else {
			// if m1 row is less than m2 
			if (m1->row < m2->row) {
				m3->append(m1->row, m1->col, m1->val);
				m1 = m1->next;
			}
			// if m2 row is less than m1
			else {
				m3->append(m2->row, m2->col, m2->val);
				m2 = m2->next;
			}
		}
	}
	// if m1 is larger than m2 add remaining values 
	while (m1 != NULL) {
		m3->append(m1->row, m1->col, m1->val);
		m1 = m1->next;
	}

	//if m2 is larger than m2 add remaining values
	while (m2 != NULL) {
		m3->append(m2->row, m2->col, m2->val);
		m2 = m2->next;
	}

}

// someone plz check this 
// inserts a node to back of linked list 
void LinkedMatrix::append(int row, int col, int val) {
	
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

// prints all elements of the linked list 
// the parameter is the reference of the head of the linked list 
void LinkedMatrix::print(Node* node) {

	while (node != NULL) {

		std::cout << node->val << "->";
		node = node->next;
	}
	std::cout << "nullptr";
}

//Function takes in a linkedMatrix and creates/returns a 2dVector of the resulting matrix
//Adding too many elements back in, still in the process of DEBUGGING
std::vector<std::vector<int>> LinkedMatrix::Linked2Vector(int rows, int cols){
	std::vector<std::vector<int>> matrix;
	std::vector<int> row;
	Node* temp = this->head;

	for(int i=0; i < rows; i++){
		for(int j=0; j < cols; j++){
			//if a nonzero element exists push that value into row
			if(temp->row == i && temp->col == j){
				row.push_back(temp->val);
				std::cout << temp->val << " ";
				//std::cout << "Lmatrix- row:" << temp->row << " col:" << temp->col << " val:" << temp->val << std::endl;
				//move temp ptr to the next node
				if(temp->next != nullptr){
				temp= temp->next;
				}
			}
			//else push a zero into that spot
			else{
				std::cout << "0 ";
				row.push_back(0);
				}
		}
		matrix.push_back(row);
		std::cout << std::endl;
	}
	std::cout << "Returning vector to main!" << std::endl;
return matrix;

}