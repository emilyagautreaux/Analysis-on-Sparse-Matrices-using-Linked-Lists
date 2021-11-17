

#include <iostream>
#include "Node.h"



// constrcuter for each node
// row will hold the row in which the value is located in the 2d matrix
// col will hold the ciol in which the value is located in the 2d matrix
//val will hold the non 0 integer in the 2d matrix at location (row,col)
Node::Node(int arow, int acol, int aval) {

	this->row = arow;
	this->col = acol;
	this->val = aval;
	this->next = NULL;

}

//deconstructor
Node::~Node() {

	
}