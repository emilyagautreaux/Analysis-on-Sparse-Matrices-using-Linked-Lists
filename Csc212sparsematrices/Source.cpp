#include "LinkedMatrix.h"
#include "Node.h"
#include<fstream>
#include<sstream>
#include <iostream>



//function declarations
LinkedMatrix* ReadFile(std::string fileName);



int main(int argc, char* argv[]) {
	//arguments ./prog matrix1.txt matrix2.txt
	std::string file1 = argv[1];
	std::string file2 = argv[2];

	//testing readFile function with matrix txt files
	LinkedMatrix* m1=ReadFile(file1);
	std::cout << std::endl;
	LinkedMatrix* m2=ReadFile(file2);

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
LinkedMatrix* ReadFile(std::string fileName) {
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

	inFile.close();
	return matrix;
}

