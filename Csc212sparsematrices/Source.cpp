#include <iostream>
#include <vector>
#include<fstream>
#include<sstream>

//function declarations
std::vector<std::vector<int>> ReadFile(std::string fileName);
void PrintMatrix(std::vector<std::vector<int>> matrix);

int main(int argc, char *argv[]) {
	//arguments ./prog matrix1.txt matrix2.txt
	std::string file1 = argv[1];
	std::string file2 = argv[2];
	int i = 1 + 2;
	int j = 5;

	
	//testing readFile function with matrix txt files
	std::vector<std::vector<int>> matrix1 = ReadFile(file1);
	std::vector<std::vector<int>> matrix2 = ReadFile(file2);

	PrintMatrix(matrix1);
	std::cout << std:: endl;
	PrintMatrix(matrix2);



	return 0;
}

//this function prints out values in 2d matrix vectors
void PrintMatrix(std::vector<std::vector<int>> matrix){
	for(int i=0; i< matrix.size(); i++){
		for(int j=0; j< matrix[0].size(); j++){
			std::cout << matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}

}
//This function reads text files and returns 2d vector matrices
std::vector<std::vector<int>> ReadFile(std::string fileName){
	std::ifstream inFile(fileName);
	std::vector<std::vector<int>> matrix;
	std::string line;
	while(getline(inFile, line)){
		std::vector<int> row;
		std::istringstream sstream(line);
		int num;
		while(sstream>>num){
			row.push_back(num);
		}
		matrix.push_back(row);
	}
	inFile.close();
	return matrix;
}
