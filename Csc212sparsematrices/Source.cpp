#include "LinkedMatrix.h"
#include "Node.h"
#include <vector>
#include<fstream>
#include<sstream>
#include <iostream>



//function declarations
std::vector<std::vector<int>> ReadFile(std::string fileName);
void PrintMatrix(std::vector<std::vector<int>> matrix);
void makeList(std::vector<std::vector<int>>* matrix1, std::vector<std::vector<int>>* matrix2, LinkedMatrix* m1, LinkedMatrix* m2);


int main(int argc, char* argv[]) {
	//arguments ./prog matrix1.txt matrix2.txt
	std::string file1 = argv[1];
	std::string file2 = argv[2];

	//testing readFile function with matrix txt files
	std::vector<std::vector<int>> matrix1 = ReadFile(file1);
	std::vector<std::vector<int>> matrix2 = ReadFile(file2);

	PrintMatrix(matrix1);
	std::cout << std::endl;
	PrintMatrix(matrix2);
	std::cout << std::endl;

	LinkedMatrix* m1 = new LinkedMatrix();
	LinkedMatrix* m2 = new LinkedMatrix();

	makeList(&matrix1, &matrix2, m1, m2);

	LinkedMatrix* m3 = new LinkedMatrix();

	m3->addMatrix(m1->head, m2->head, m3);

	//m1->print(m1->head);
	std::cout << std::endl;
//	m2->print(m2->head);
	std::cout << std::endl;
	m3->print(m3->head);



	return 0;
}



// this will make two linked lists out of the 2 vectors obtained from file input
void makeList(std::vector<std::vector<int>> *matrix1, std::vector<std::vector<int>> *matrix2, LinkedMatrix *m1, LinkedMatrix *m2) {

	// fill first LinkedMatrix
	for (unsigned int i = 0; i < matrix1->size(); i++) {
		for (unsigned int j = 0; j < (*matrix1)[i].size(); j++) {
			if ((*matrix1)[i][j] != 0)
				m1->append(i, j, (*matrix1)[i][j]);
		}
	}

	// fill second LinkedMatrix
	for (unsigned int i = 0; i < matrix2->size(); i++) {
		for (unsigned int j = 0; j < (*matrix2)[i].size(); j++) {
			if ((*matrix2)[i][j] != 0)
				m2->append(i, j, (*matrix2)[i][j]);
		}
	}

}


//this function prints out values in 2d matrix vectors
void PrintMatrix(std::vector<std::vector<int>> matrix) {
	for (int i = 0; i < matrix.size(); i++) {
		for (int j = 0; j < matrix[0].size(); j++) {
			std::cout << matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}

}
//This function reads text files and returns 2d vector matrices
std::vector<std::vector<int>> ReadFile(std::string fileName) {
	std::ifstream inFile(fileName);
	std::vector<std::vector<int>> matrix;
	std::string line;
	while (getline(inFile, line)) {
		std::vector<int> row;
		std::istringstream sstream(line);
		int num;
		while (sstream >> num) {
			row.push_back(num);
		}
		matrix.push_back(row);
	}
	inFile.close();
	return matrix;
}

