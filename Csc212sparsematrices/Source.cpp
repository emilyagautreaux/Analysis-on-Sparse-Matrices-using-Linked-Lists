#include "LinkedMatrix.h"
#include "Node.h"
#include<fstream>
#include<sstream>
#include <iostream>



//function declarations
LinkedMatrix* ReadFile(std::string fileName, int &rows, int &cols);



int main(int argc, char* argv[]) {
	//arguments ./prog matrix1.txt matrix2.txt
	std::string file1 = argv[1];
	std::string file2 = argv[2];
	//the row and col count of m1 and m2
	int m1Rows, m2Rows, m1Cols, m2Cols;

	//testing readFile function with matrix txt files
	LinkedMatrix* m1=ReadFile(file1,m1Rows, m1Cols);
	//std::cout << "Matrix1 - Rows: " << m1Rows << " " << m1Cols << std::endl;
	
	LinkedMatrix* m2=ReadFile(file2, m2Rows, m2Cols);
	//std::cout << "Matrix2 - Rows: " << m2Rows << " " << m2Cols << std::endl;
	LinkedMatrix* m3 = new LinkedMatrix();

	m3->addMatrix(m1->head, m2->head);

	m1->print(m1->head);
	std::cout << std::endl;
	m2->print(m2->head);
	std::cout << std::endl;
	m3->print(m3->head);



	return 0;
}



//This function reads given text files and creates a Linked Matrix
LinkedMatrix* ReadFile(std::string fileName, int &rows, int &cols) {
	int rowCount=0, colCount;
	std::ifstream inFile(fileName);
	std::string line;
	//create a new LinkedMatrix
	LinkedMatrix* matrix = new LinkedMatrix();
	
	while (getline(inFile, line)) {
		std::istringstream sstream(line);
		int num;
		colCount = 0;
		while (sstream >> num) {
			if(num!=0){
			//if element is not zero add to linkedMatrix
			matrix->append(rowCount, colCount, num);
			//std::cout << "Row:" << rowCount << " Col: "<< colCount << " Value:"<< num << std::endl;
			}
			colCount++;
		}
		//increment rowcount
		rowCount++;
	}
	rows = rowCount;
	cols = colCount;
	inFile.close();
	return matrix;
}

