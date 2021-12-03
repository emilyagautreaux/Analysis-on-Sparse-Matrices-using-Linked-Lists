#include <iostream>
#include<vector>
#include "LinkedMatrix.h"

LinkedMatrix::LinkedMatrix() { //constructor
	head = NULL;
}

LinkedMatrix::~LinkedMatrix() { //deconstructor

	Node* current = head;
	while (current != NULL) {
		current = current->next;
		delete head;
		head = current;
	}
	head = NULL;
	
}

void LinkedMatrix::addMatrix(Node* m1,Node* m2) {

	while (m1 != NULL && m2 != NULL) { //while m1 and m2 linked lists are not empty 
		
		if (m1->row == m2->row) { // if both rows are equal 			
			if (m1->col == m2->col) { // ifcolumns are equal 
				this->append(m1->row, m1->col, m1->val + m2->val); //create new node at that row and column index and add values 
				m1 = m1->next; //traverse to next node 
				m2 = m2->next; //traverse to next node
			}			
			else { //m1 and m2 node are not at the same index 
				if (m1->col < m2->col) { // if m1 column is less than m2 column
					this->append(m1->row, m1->col, m1->val); //create new node with m1 row, column, and value
					m1 = m1->next; //traverse to next node 
				}				
				else { // m2 column less than m1 
					this->append(m2->row, m2->col, m2->val); //create new node with m2 row, column, and value 
					m2 = m2->next; //traverse to next node 
				}
			}
		}		
		else { // rows are not equal 			
			if (m1->row < m2->row) { // if m1 row is less than m2 
				this->append(m1->row, m1->col, m1->val); //append index and value to linked list 
				m1 = m1->next; //go to the next node 
			}			
			else { // if m2 row is less than m1
				this->append(m2->row, m2->col, m2->val); //append index and value to linked list 
				m2 = m2->next; //go to next node 
			}
		}
	}	
	while (m1 != NULL) { // if m1 is larger than m2 add remaining values 
		this->append(m1->row, m1->col, m1->val); //append nodes of remaining values 
		m1 = m1->next; 
	}	
	while (m2 != NULL) { //if m2 is larger than m2 add remaining values
		this->append(m2->row, m2->col, m2->val); //append nodes of remaining values 
		m2 = m2->next;
	}
}

void LinkedMatrix::subtractMatrix(Node* m1, Node* m2){
	
	while (m1 != NULL && m2 != NULL) { //while m1 and m2 linked lists are not empty
		
		if (m1->row == m2->row) { // if both rows are equal 
			
			if (m1->col == m2->col) { // if columns are equal 
				this->append(m1->row, m1->col, m1->val - m2->val); // add node to end of linked list containing the index and value after subtracting m2 from m1
				m1 = m1->next; //traverse to next node
				m2 = m2->next; //traverse to next node 
			}			
			else {  //columns are not equal 
				if (m1->col < m2->col) { // if m1 column is less than m2
					this->append(m1->row, m1->col, m1->val); //add values to linked list 
					m1 = m1->next; //move to next node 
				}
				else { // m2 column is less than m1 
					this->append(m2->row, m2->col, m2->val); //add values to end of linked list 
					m2 = m2->next; //traverse to next node 
				}
			}
		}		
		else { // rows are not equal 			
			if (m1->row < m2->row) {// if m1 row is less than m2 
				this->append(m1->row, m1->col, m1->val); //append node to linked list 
				m1 = m1->next; //move to next node 
			}			
			else { // if m2 row is less than m1
				this->append(m2->row, m2->col, m2->val); //append node to linked list 
				m2 = m2->next; //go to the next node 
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

int LinkedMatrix::find(Node* m, int r, int c) { //return value of node in linked list given index   

	while (m != NULL) { //while linked list is not empty 

		if (m->row == r && m->col == c) { // traverse through linked list until node containing row and column number is found 
			return m->val; //return value 
		}
		m = m->next; //move to next node 
	}

	return 0;
}

bool LinkedMatrix::multiplyMatrix(Node* m1, Node* m2, int m1Rows, int m2Cols,int m1Cols){

	int num1;
	int num2;
	int sum;
		
	if(m1Rows == m2Cols){	//multiplication is only possible if the number of rows in m1 is equal to number of columns in m2 
		for (unsigned int i = 0; i < m1Rows; i++) { // //multiplication is completed across rows of m1 and columns of m2 
			for (unsigned int j = 0; j < m2Cols; j++) {
				sum = 0; 
				for (unsigned int k = 0; k < m1Cols; k++) { //iterate down the column of m2
					num1 = find(m1, i, k); // return m1 value at index
					num2 = find(m2, k, j); //return m2 value at index
					sum += num1 * num2; //multiply values and add to sum 
				}
				if (sum != 0) { // once computation is completed 
					this->append(i, j, sum); //insert new node containing the sum at specific row and column index
				}
			}
		}	
		return false;
	}
	else {
		return true;
	}
}
 
void LinkedMatrix::append(int row, int col, int val) { // inserts a node to back of linked list

	Node* newNode = new Node(row, col, val); //create new node 
	Node* temp = head; //initialize temporary pointer that starts at the head of linked list 

	if (head == NULL) //if head is pointing to NULL - at the end of the list 
		head = newNode; //have head point to new node 
	
	else { //linked list contains nodes 
		Node* temp = head; //initialize temporary pointer that starts at the head of linked list 
		//traverse through linked list until last node is found  
		while (temp->next != NULL) { // while temp pointing to node whose next pointer is another node (not NULL)
			temp = temp->next; //have temp point to next node 
		}
		//last node is found - temp->next = NULL
		temp->next = newNode; //move next pointer of the previous last node to newly created node 
	}	
}
bool LinkedMatrix::inverseMatrix(Node* m1, int m1rows, int m1cols){	

	if(m1->next == NULL){ //if there is one node in the linked list 
		m1->val = static_cast<double>(1.0/m1->val); //take the inverse of that number;
		return false;
	}

	else if((m1rows == 2 ) && (m1cols == 2)){ //if 2x2 square matrix 
		double invdeterminant = 1.0/(static_cast<double>((m1->val * m1->next->next->next->val)) - static_cast<double>((m1->next->val * m1->next->next->val))); // 1/(ad-bc)
		std::cout<<invdeterminant<<std::endl;
		
		/*
		[d   -b]
		[-c   a]
		*/

		//calculating adjugate
		this->append(0,0,invdeterminant * m1->next->next->next->val); // first node value = last node value
		this->append(0,1,invdeterminant * -m1->next->val); //second node value = negative of second node value
		this->append(1,0, invdeterminant * -m1->next->next->val); //third node value = negative of third node value
		this->append(1,1,invdeterminant * m1->val); //last node value = first node value
		
		//other method I tried: 
		// m1->next->next->next->val = invdeterminant * m1->val; //last node value = first node value
		// m1->next->val = invdeterminant * -m1->next->val; //second node value = negative of second node value
		// m1->next->next->val = invdeterminant * -m1->next->next->val; //third node value = negative of third node value
		// m1->val = invdeterminant * m1->next->next->next->val; // first node value = last node value 	

		return false;
	}else if ((m1rows ==3) && (m1cols ==3)){
		float determinant = 0;
		for (int i =0; i<3; i++){ //calculate determinant
			determinant = determinant + find(m1,0,i) * (find(m1,1,(i+1)%3) * find(m1,2,(i+2)%3) - find(m1,1,(i+2)%3) * find(m1,2,(i+1)%3)) ;
		}
		std::cout<<"determinant: "<<determinant<<std::endl;
		
		for(int i=0; i<3; i++){
			for( int j =0; j<3; j++){ //calculate invserse
				double inv = find(m1,(j+1)%3,(i+1)%3) * find(m1,(j+2)%3,(i+2)%3) - (find(m1,(j+1)%3,(i+2)%3) * find(m1,(j+2)%3,(i+1)%3)) / determinant;
				this->append(i,j,inv);
			}
		}
		return false;
	}
	else {
		return true;
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

//Convert Matrixlinked list to 2D vector 
void LinkedMatrix::Linked2Vector(int rows1, int cols1,int rows2, int cols2, std::vector<std::vector<int>> &vector, std::string type){
	Node* temp = this->head;
	int rows = 0, cols = 0;
	std::vector<int> row;
	//The parameters of matrices needed to print vary depending on which operation (if any) have been preformed
	if (type == "Matrix 1"){
		rows = rows1;
		cols = cols1;
	}

	if (type == "Matrix 2"){
		rows = rows2;
		cols = cols2;
	}	
	
	if( type == "Addition" || type == "Subtraction"){
		if((rows1 * cols1) >= (rows2 * cols2) ){ //if matrix 1 is the same size or larger that matrix 2 
			rows = rows1;
			cols = cols1;
		}
		else if((rows1 * cols1) < (rows2 * cols2)) { //if matrix 2 is larger 
			rows = rows2;
			cols = cols2;
		}
	}

	if(type == "Multiplication" && rows1 == cols2 && this->head != NULL){ //dimensions would be m1rows x m2cols
		rows = rows1;
		cols = cols2;
	}

	if (type == "Inverse"){
		rows = rows1;
		cols = cols1;
	}	
	// Once the parameters of the matrix to be printed are found, a set of nested for loops
	//cycle over the linked list. If there is a nonzero element at that particular [row]&[col] that value is
	//pushed into the appropriate spot, if no elements exist at that row/col that position is filled with a zero	
	for(int i=0; i < rows; i++){		
		for(int j=0; j < cols; j++){
			if(temp->row == i && temp->col == j){ //if a nonzero element exists push that value into row
				row.push_back(temp->val);
				if(temp->next != nullptr){
					temp= temp->next;
				}
			}
			else{ //push a zero into that spot 
				row.push_back(0);
			}
		}
		vector.push_back(row);
		row.clear();
	}
}

