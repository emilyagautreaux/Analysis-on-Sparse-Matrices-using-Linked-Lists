#include "LinkedMatrix.h"
#include "Node.h"
#include<fstream>
#include<sstream>
#include <iostream>
#include<vector>
//#include <SFML/Graphics.hpp>

//function declarations
LinkedMatrix* ReadFile(std::string fileName, int &rows, int &cols);
void PrintVec(std::vector<std::vector<int>> vector);

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

//arguments ./prog matrix1.txt matrix2.txt
int main(int argc, char* argv[]) {

    std::string file1 = argv[1];
	std::string file2 = argv[2];
	
	//the row and col count of m1 and m2
	int m1Rows, m2Rows, m1Cols, m2Cols;

	LinkedMatrix* m1 = ReadFile(file1, m1Rows, m1Cols);
	LinkedMatrix* m2 = ReadFile(file2, m2Rows, m2Cols);

	LinkedMatrix* m3 = new LinkedMatrix(); //for addition
	LinkedMatrix* m4 = new LinkedMatrix(); //for multiplication
	LinkedMatrix* m5 = new LinkedMatrix(); //for subtraction

	m3->addMatrix(m1->head, m2->head); //add 
	m4->multiplyMatrix(m1->head, m2->head, m1Rows, m2Cols, m1Cols); //multiply
	m5->subtractMatrix(m1->head, m2->head); //subtract
	
	/*
	//Print linked list output 
	m1->print(m1->head, "Matrix 1");	
	m2->print(m2->head, "Matrix 2");	
	m3->print(m3->head, "Addition");	
	m4->print(m4->head, "Multiplication");	
	m5->print(m5->head, "Subtraction");

	//print output in matrix format
	std::vector<std::vector<int>> vector = m1->Linked2Vector(m1Rows, m1Cols, m2Rows, m2Cols, "Matrix 1");
	PrintVec(vector);
	std::vector<std::vector<int>> vector2 = m4->Linked2Vector(m1Rows, m1Cols, m2Rows, m2Cols, "Multiplication");
	PrintVec(vector2);
	*/


		

		// object for our window of size 1500x900
		sf::RenderWindow window(sf::VideoMode(1500, 900), "Sparse Matrix Operations!");
	
		// font object 
		sf::Font font;
		
		//Load and check the availability of the font file
		if (!font.loadFromFile("font.ttf"))
		{
			std::cout << "can't load font" << std::endl;
		}
		
		// creating a text variable named text 
		sf::String s;
		sf::Text text(s, font, 75);
		text.setFillColor(sf::Color::Red);

		// creating a text variable named text2
		sf::String s1;
		sf::Text text1(s1, font, 75);
		text1.setFillColor(sf::Color::Cyan);

		//// creating a text variable named text 3
		sf::String s2;
		sf::Text text2(s2, font, 75);
		text2.setFillColor(sf::Color::Green);


		// making sure window is open 
		while (window.isOpen())
		{	
			// an event object that will store any type of event that occurs, in our case,
			// an event will be holding user input from keyboard 
			sf::Event event;
			// while there is an event that has occured....
			while (window.pollEvent(event))
			{
				
				switch (event.type) {

				
				// we can create different events for different keys pressed which will give us a way for user 
				// to choose what operation they want


					// if they close the window, close the window and break out of loop
				case sf::Event::Closed:
					window.close();
					break;
				
				// if the event is a keypressed 
				case sf::Event::KeyPressed:
					// if that event is a space from keyboard
					if (event.key.code == sf::Keyboard::Space) {
					
						
						// make m1 into vector 
						std::vector<std::vector<int>> vector = m1->Linked2Vector(m1Rows, m1Cols, m2Rows, m2Cols, "Matrix 1");

						// this will take all values of m1 and append them into a string named "s"
						// it will then assign string s to the text varible using text.setstring
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
					
						// same as above but for m2 and text1 object
						std::vector<std::vector<int>> vector2 = m2->Linked2Vector(m1Rows, m1Cols, m2Rows, m2Cols, "Matrix 2");
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
							text1.setString(s1);
						}

						// adding the matricies and storing them into m3
						m3->addMatrix(m1->head, m2->head);

						// make m3 into vector 
						std::vector<std::vector<int>> vector3 = m3->Linked2Vector(m1Rows, m1Cols, m2Rows, m2Cols,"Addition");

						//same as above but for m3 and text2 object
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
							text2.setString(s2);
						}

						break;

					}
					
				}
				
			}

			// .clear will clear the window 
			// .setposition will put our object at a specific cooridnate
			// draw will put the object on screen 
			// display will show us the window

			//window.clear();
			text.setPosition(10, 200);
			text1.setPosition(350, 200);
			text2.setPosition(700, 200);
			window.draw(text);
			window.draw(text1);
			window.draw(text2);
			window.display();
		}


	return 0;
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
