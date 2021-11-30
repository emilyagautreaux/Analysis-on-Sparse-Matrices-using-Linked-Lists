#include <iostream>
#include<vector>
#include "LinkedMatrix.h"


LinkedMatrix::LinkedMatrix() { //constructor
	head = NULL;
}

LinkedMatrix::~LinkedMatrix() { //deconstrucotr (idk if this will work, it needs testing) 

	Node* current = head;
	while (current != NULL) {
		current = current->next;
		delete head;
		head = current;
	}
	head = NULL;
	
}

void LinkedMatrix::addMatrix(Node* m1,Node* m2) {

	while (m1 != NULL && m2 != NULL) {

		// if both rows are equal 
		if (m1->row == m2->row) {

			// if columns are equal 
			if (m1->col == m2->col) {
				this->append(m1->row, m1->col, m1->val + m2->val);
				m1 = m1->next;
				m2 = m2->next;
			}
			// m1 column being less than m2
			else {
				if (m1->col < m2->col) {
					this->append(m1->row, m1->col, m1->val);
					m1 = m1->next;
				}
				// m2 column less than m1 
				else {
					this->append(m2->row, m2->col, m2->val);
					m2 = m2->next;
				}
			}
		}		
		else { // rows are not equal 			
			if (m1->row < m2->row) { // if m1 row is less than m2 
				this->append(m1->row, m1->col, m1->val);
				m1 = m1->next;
			}			
			else { // if m2 row is less than m1
				this->append(m2->row, m2->col, m2->val);
				m2 = m2->next;
			}
		}
	}	
	while (m1 != NULL) { // if m1 is larger than m2 add remaining values 
		this->append(m1->row, m1->col, m1->val);
		m1 = m1->next;
	}

	//if m2 is larger than m2 add remaining values
	while (m2 != NULL) {
		this->append(m2->row, m2->col, m2->val);
		m2 = m2->next;
	}
}

void LinkedMatrix::subtractMatrix(Node* m1, Node* m2){
	while (m1 != NULL && m2 != NULL) {
		
		if (m1->row == m2->row) { // if both rows are equal 
			
			if (m1->col == m2->col) { // if columns are equal 
				this->append(m1->row, m1->col, m1->val - m2->val);
				m1 = m1->next;
				m2 = m2->next;
			}			
			else { // m1 column being less than m2
				if (m1->col < m2->col) {
					this->append(m1->row, m1->col, m1->val);
					m1 = m1->next;
				}
				else { // m2 column less than m1 
					this->append(m2->row, m2->col, m2->val);
					m2 = m2->next;
				}
			}
		}		
		else { // rows are not equal 			
			if (m1->row < m2->row) {// if m1 row is less than m2 
				this->append(m1->row, m1->col, m1->val);
				m1 = m1->next;
			}			
			else { // if m2 row is less than m1
				this->append(m2->row, m2->col, m2->val);
				m2 = m2->next;
			}
		}
	}	
	
	while (m1 != NULL) { // if m1 is larger than m2 add remaining values 
		this->append(m1->row, m1->col, m1->val);
		m1 = m1->next;
	}	
	
	while (m2 != NULL) { //if m2 is larger than m2 add remaining values
		this->append(m2->row, m2->col, m2->val);
		m2 = m2->next;
	}
}


int LinkedMatrix::find(Node* m, int r, int c) {

	while (m != NULL) {

		if (m->row == r && m->col == c) {
			return m->val;
		}
		m = m->next;
	}

	return 0;
}

void LinkedMatrix::multiplyMatrix(Node* m1, Node* m2, int m1Rows, int m2Cols,int m1Cols){

	int num1;
	int num2;
	int sum;
		
	if(m1Rows == m2Cols){	
		for (unsigned int i = 0; i < m1Rows; i++) {
			for (unsigned int j = 0; j < m2Cols; j++) {
				sum = 0;
				for (unsigned int k = 0; k < m1Cols; k++) {
					num1 = find(m1, i, k);
					num2 = find(m2, k, j);
					sum += num1 * num2;
				}
				if (sum != 0) {
					this->append(i, j, sum);
				}
			}
		}	
	}
	else {
		std::cout << "unable to do this operation";
	}
}
 
void LinkedMatrix::append(int row, int col, int val) { // inserts a node to back of linked list

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

// print linked list 
void LinkedMatrix::print(Node* node, std::string type) { // the parameter is the reference of the head of the linked list 

	std::cout<<type<<std::endl;

	while (node != NULL) {

		std::cout << node->val << "->";
		node = node->next;
	}
	std::cout << "nullptr";
}

//Convert linked list to 2D vector 
std::vector<std::vector<int>> LinkedMatrix::Linked2Vector(int m1rows, int m1cols, int m2rows, int m2cols, std::string type){
	
	std::vector<std::vector<int>> matrix;
	Node* temp = this->head;
	std::vector<int> row;

	if (type == "Matrix 1"){
		for(int i=0; i < m1rows; i++){		
			for(int j=0; j < m1cols; j++){
				if(temp->row == i && temp->col == j){ //if a nonzero element exists push that value into row
					row.push_back(temp->val);
					//std::cout << temp->val << " ";
					//std::cout << "Lmatrix- row:" << temp->row << " col:" << temp->col << " val:" << temp->val << std::endl;
					//move temp ptr to the next node
					if(temp->next != nullptr){
						temp= temp->next;
					}
				}
				else{ //push a zero into that spot 
					row.push_back(0);
				}
			}
			matrix.push_back(row);
			row.clear();
		}	
		return matrix;
	}
	
	if(type == "Matrix 2"){
		for(int i=0; i < m2rows; i++){		
			for(int j=0; j < m2cols; j++){
				if(temp->row == i && temp->col == j){ //if a nonzero element exists push that value into row
					row.push_back(temp->val);
					//std::cout << temp->val << " ";
					//std::cout << "Lmatrix- row:" << temp->row << " col:" << temp->col << " val:" << temp->val << std::endl;
					//move temp ptr to the next node
					if(temp->next != nullptr){
						temp= temp->next;
					}
				}
				else{ //push a zero into that spot 
					row.push_back(0);
				}
			}
			matrix.push_back(row);
			row.clear();
		}	
		return matrix;	
	}
	
	if(type == "Multiplication" && m1rows == m2cols && this->head != NULL){ //dimensions would be m1rows x m2cols
		for(int i=0; i < m1rows; i++){		
			for(int j=0; j < m2cols; j++){
				if(temp->row == i && temp->col == j){ //if a nonzero element exists push that value into row
					row.push_back(temp->val);
					//std::cout << temp->val << " ";
					//std::cout << "Lmatrix- row:" << temp->row << " col:" << temp->col << " val:" << temp->val << std::endl;
					//move temp ptr to the next node
					if(temp->next != nullptr){
						temp= temp->next;
					}
				}
				else{ //push a zero into that spot 
					row.push_back(0);
				}
			}
			matrix.push_back(row);
			row.clear();
		}	
		return matrix;	
	}
	
	if((type == "Addition") || (type == "Subtraction") ){ //want dimensions of largest matrix being added
		if((m1rows * m1cols) >= (m2rows * m2cols) ){ //if matrix 1 is the same size or larger that matrix 2 
			for(int i=0; i < m1rows; i++){		
				for(int j=0; j < m1cols; j++){
					if(temp->row == i && temp->col == j){ //if a nonzero element exists push that value into row
						row.push_back(temp->val);
						//std::cout << temp->val << " ";
						//std::cout << "Lmatrix- row:" << temp->row << " col:" << temp->col << " val:" << temp->val << std::endl;
						//move temp ptr to the next node
						if(temp->next != nullptr){
							temp= temp->next;
						}
					}
					else{ //push a zero into that spot 
						row.push_back(0);
					}
				}
				matrix.push_back(row);
				row.clear();
			}	
			return matrix;	
		}
		else if ((m1rows * m1cols) < (m2rows * m2cols)){ //if matrix 2 is larger 
			for(int i=0; i < m2rows; i++){		
				for(int j=0; j < m2cols; j++){
					if(temp->row == i && temp->col == j){ //if a nonzero element exists push that value into row
						row.push_back(temp->val);
						//std::cout << temp->val << " ";
						//std::cout << "Lmatrix- row:" << temp->row << " col:" << temp->col << " val:" << temp->val << std::endl;
						//move temp ptr to the next node
						if(temp->next != nullptr){
							temp= temp->next;
						}
					}
					else{ //push a zero into that spot 
						row.push_back(0);
					}
				}
				matrix.push_back(row);
				row.clear();
			}	
			return matrix;
		}
	}
}