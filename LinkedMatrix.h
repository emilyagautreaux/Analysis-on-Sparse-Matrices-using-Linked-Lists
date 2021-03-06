#pragma once
#include <iostream>
#include "Node.h"
#include <vector>


class LinkedMatrix {

private:

public:
	Node* head;
	LinkedMatrix();
	void append(int row, int col, double val);
	~LinkedMatrix();
	void print(Node* node, std::string type);
	void Linked2Vector(int rows1, int cols1, int rows2, int cols2,std::vector<std::vector<double>> &vector, std::string type);
	void addMatrix(Node* m1, Node *m2);
	void subtractMatrix(Node* m1, Node* m2);
	bool multiplyMatrix(Node* m1, Node* m2, int m1Rows, int m2Cols, int m1Cols);
	bool inverseMatrix(Node* m1, int m1rows, int m1cols);
	double find(Node* m, int r, int c);
};

