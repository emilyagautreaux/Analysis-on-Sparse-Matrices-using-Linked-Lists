#include "LinkedMatrix.h"
#include "Node.h"
#include<fstream>
#include<sstream>
#include <iostream>
#include<vector>
#include <SFML/Graphics.hpp>



//function declarations
LinkedMatrix* ReadFile(std::string fileName, int &rows, int &cols);
void PrintVec(std::vector<std::vector<int>> vector);

//arguments ./prog matrix1.txt matrix2.txt
int main(int argc, char* argv[]) {

	std::string file1 = argv[1];
	std::string file2 = argv[2];

	//the row and col count of m1 and m2
	int m1Rows, m2Rows, m1Cols, m2Cols;

	//testing readFile function with matrix txt files
	LinkedMatrix* m1 = ReadFile(file1, m1Rows, m1Cols);
	//std::cout << "Matrix1 - Rows: " << m1Rows << " " << m1Cols << std::endl;	
	LinkedMatrix* m2 = ReadFile(file2, m2Rows, m2Cols);
	//std::cout << "Matrix2 - Rows: " << m2Rows << " " << m2Cols << std::endl;

	LinkedMatrix* m3 = new LinkedMatrix(); //for addition
	LinkedMatrix* m4 = new LinkedMatrix(); //for multiplication
	LinkedMatrix* m5 = new LinkedMatrix(); //for subtraction


	m3->addMatrix(m1->head, m2->head);
	LinkedMatrix* m2=ReadFile(file2, m2Rows, m2Cols);
	
	LinkedMatrix* m3 = new LinkedMatrix();
	LinkedMatrix* m4 = new LinkedMatrix();


	

	std::vector<std::vector<int>> vector = m1->Linked2Vector(m1Rows, m1Cols);
	PrintVec(vector);	

	m3->addMatrix(m1->head, m2->head);
	m4->multiplyMatrix(m1->head, m2->head, m1Rows, m2Cols, m1Cols); 
	m5->subtractMatrix(m1->head, m2->head);


	std::cout<<"Matrix 1"<<std::endl;
	m1->print(m1->head);
	std::cout << std::endl;
	std::cout<<"Matrix 2"<<std::endl;
	m2->print(m2->head);
	std::cout << std::endl;
	std::cout<<"Addition"<<std::endl;
	m3->print(m3->head);
	std::cout << std::endl;
	std::cout<<"Multiplication"<<std::endl;
	m4->print(m4->head);
	std::cout << std::endl;
	std::cout<<"Subtraction"<<std::endl;
	m4->print(m4->head);

	std::cout << std::endl;


	
	
		sf::RenderWindow window(sf::VideoMode(1500, 900), "Sparse Matrix Operations!");
	
		sf::Font font;
		
		//Load and check the availability of the font file
		if (!font.loadFromFile("font.ttf"))
		{
			std::cout << "can't load font" << std::endl;
		}
		
		sf::String s;
		sf::Text text(s, font, 75);
		text.setFillColor(sf::Color::Red);

		sf::String s1;
		sf::Text text2(s1, font, 75);
		text2.setFillColor(sf::Color::Cyan);

		sf::String s2;
		sf::Text text3(s2, font, 75);
		text3.setFillColor(sf::Color::Green);

		while (window.isOpen())
		{
			sf::Event event;
			while (window.pollEvent(event))
			{
				
				switch (event.type) {

				case sf::Event::Closed:
					window.close();
					break;
				//case sf::Event::TextEntered:
				//	if (event.text.unicode >= 32 && event.text.unicode <= 126)
					//	s += (char)event.text.unicode;
					//else if (event.text.unicode == 8 && s.getSize() > 0)
					//	s.erase(s.getSize() - 1, s.getSize());

				//	text.setString(s);
				//	break;
				case sf::Event::KeyPressed:
					if (event.key.code == sf::Keyboard::Space) {
					
						
						std::vector<std::vector<int>> vector = m1->Linked2Vector(m1Rows, m1Cols);
						for (int i = 0; i < vector.size(); i++) {

							for (int j = 0; j < vector[i].size(); j++) {
								std::stringstream ss;
								std::string str;
								ss << vector[i][j];
								ss >> str;
								s += str + " ";
								//text.setString(s);
							}
							s += "\n";
							text.setString(s);
						}
					
						std::vector<std::vector<int>> vector2 = m2->Linked2Vector(m2Rows, m2Cols);
						for (int i = 0; i < vector2.size(); i++) {

							for (int j = 0; j < vector2[i].size(); j++) {
								std::stringstream tt;
								std::string str;
								tt << vector2[i][j];
								tt >> str;
								s1 += str + " ";
								//text2.setString(s1);
							}
							s1 += "\n";
							text2.setString(s1);
						}


						m3->addMatrix(m1->head, m2->head);

						std::vector<std::vector<int>> vector3 = m3->Linked2Vector(3, 3);
						for (int i = 0; i < vector3.size(); i++) {

							for (int j = 0; j < vector3[i].size(); j++) {
								std::stringstream tt;
								std::string str;
								tt << vector3[i][j];
								tt >> str;
								s2 += str + " ";
								//text2.setString(s1);
							}
							s2 += "\n";
							text3.setString(s2);
						}

						break;

					}
					
				}
				
			}

			//window.clear();
			text.setPosition(10, 200);
			text2.setPosition(350, 200);
			text3.setPosition(700, 200);
			window.draw(text);
			window.draw(text2);
			window.draw(text3);
			window.display();
		}

	

	

	return 0;
}

//This function reads given text files and creates a Linked Matrix
LinkedMatrix* ReadFile(std::string fileName, int &rows, int &cols) {
	int rowCount=0, colCount=0;
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

//test function to print out 2dVector
void PrintVec(std::vector<std::vector<int>> vector){
	
	for(int i=0; i<vector.size(); i++){
		for(int j=0; j<vector[i].size(); j++){
			std::cout << vector[i][j] << " ";
		}
		std::cout << std::endl;
	}
	
}


