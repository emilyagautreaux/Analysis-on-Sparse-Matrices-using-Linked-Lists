#include "LinkedMatrix.h"
#include "Node.h"
#include<fstream>
#include<sstream>
#include <iostream>
#include<vector>
#include <SFML/Graphics.hpp>

//function declarations
LinkedMatrix* ReadFile(std::string fileName, int &rows, int &cols);
void PrintVec(std::vector<std::vector<int> > vector);


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

	//LinkedMatrix* m3 = new LinkedMatrix(); //for addition
	//LinkedMatrix* m4 = new LinkedMatrix(); //for multiplication
	//LinkedMatrix* m5 = new LinkedMatrix(); //for subtraction
	LinkedMatrix *m6 = new LinkedMatrix(); //for inverse

	//m3->addMatrix(m1->head, m2->head); //add 
	//m4->multiplyMatrix(m1->head, m2->head, m1Rows, m2Cols, m1Cols); //multiply
	//m5->subtractMatrix(m1->head, m2->head); //subtract
	m6->inverseMatrix(m1->head, m1Rows, m1Cols); //inverse
	
	
	//Print linked list output 
	// m1->print(m1->head, "Matrix 1");	
	// m2->print(m2->head, "Matrix 2");	
	// m3->print(m3->head, "Addition");	
	// m4->print(m4->head, "Multiplication");	
	// m5->print(m5->head, "Subtraction");
	m6->print(m6->head, "Inverse");


	//print output in matrix format
	// std::vector<std::vector<int>> vector = m1->Linked2Vector(m1Rows, m1Cols, m2Rows, m2Cols, "Matrix 1");
	// PrintVec(vector);
	// std::vector<std::vector<int>> vector2 = m4->Linked2Vector(m1Rows, m1Cols, m2Rows, m2Cols, "Multiplication");
	// PrintVec(vector2);
	

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
		sf::Text text(s, font, 25);
		text.setFillColor(sf::Color::Black);

		// creating a text variable named text2
		sf::String s1;
		sf::Text text1(s1, font, 25);
		text1.setFillColor(sf::Color::Black);

		//// creating a text variable named text 3
		sf::String s2;
		sf::Text text2(s2, font, 25);
		text2.setFillColor(sf::Color::Black);


		sf::String s3;
		sf::Text text3(s3, font, 25);
		text3.setFillColor(sf::Color::Black);

		sf::String s4;
		sf::Text text4(s4, font, 25);
		text4.setFillColor(sf::Color::Black);
		s4 = "*";
		text4.setString(s4);

		sf::String s5;
		sf::Text text5(s5, font, 25);
		text5.setFillColor(sf::Color::Black);
		s5 = "=";
		text5.setString(s5);


		sf::String info;
		sf::Text infotext(info, font, 25);
		infotext.setFillColor(sf::Color::Black);
		info = "This program takes in input of two sparse matricies and uses linked lists to do mathematical operations on them";
		info += "\nYou can perform an operation by left clicking an operation type.\n";
		info += "You may only do one operation per execution of the program and input sizes for a matrix is limited due to screen space.\n";
		info += "This perform operations such as add, multiply, subtract or inverse multiply,";
		info += " of the matrices in their linked list \nform with only non zero values.";
		info += "The result should consist of a sparse matrix, obtained by operating the two input matrices.";
		info += "\n \n \n Example: M1+M2=M3, M1 and M2 being input from files and M3 being the result.";
		infotext.setString(info);
		infotext.setPosition(50, 90);

		bool op = false;
		bool inputscreen = false;
		bool infoscreen = false;
		
		sf::Texture background;
		sf::Sprite backgroundImage;

		if (!background.loadFromFile("background.png"))
			std::cout << "Error: Could not display " << std::endl;
		backgroundImage.setTexture(background);
		backgroundImage.setScale(10000, 1000);


		sf::Texture backButton;
		sf::Sprite backButtonImage;
		if (!backButton.loadFromFile("back.png"))
			std::cout << "Can't find the image" << std::endl;
		backButtonImage.setPosition(2, 2);

		float backButtonWidth = backButtonImage.getLocalBounds().width;
		float backButtonHeight = backButtonImage.getLocalBounds().height;
		backButtonImage.setTexture(backButton);

		sf::Texture infoButton;
		sf::Sprite infoButtonImage;
		if (!infoButton.loadFromFile("info.png"))
			std::cout << "Can't find the image" << std::endl;
		infoButtonImage.setPosition(100, 100);

		float infoButtonWidth = infoButtonImage.getLocalBounds().width;
		float infoButtonHeight = infoButtonImage.getLocalBounds().height;
		infoButtonImage.setTexture(infoButton);

		sf::Texture addButton;
		sf::Sprite addButtonImage;
		if (!addButton.loadFromFile("add.png"))
			std::cout << "Can't find the image" << std::endl;
		addButtonImage.setPosition(50.0, 500.0);

		float addButtonWidth = addButtonImage.getLocalBounds().width;
		float addButtonHeight = addButtonImage.getLocalBounds().height;
		addButtonImage.setTexture(addButton);

		sf::Texture multButton;
		sf::Sprite multButtonImage;
		if (!multButton.loadFromFile("multiply.png"))
			std::cout << "Can't find the image" << std::endl;
		multButtonImage.setPosition(200, 500);

		float multButtonWidth = multButtonImage.getLocalBounds().width;
		float multButtonHeight = multButtonImage.getLocalBounds().height;
		multButtonImage.setTexture(multButton);

		sf::Texture subButton;
		sf::Sprite subButtonImage;
		if (!subButton.loadFromFile("subtract.png"))
			std::cout << "Can't find the image" << std::endl;
		subButtonImage.setPosition(500, 500);

		float subButtonWidth = subButtonImage.getLocalBounds().width;
		float subButtonHeight = subButtonImage.getLocalBounds().height;
		subButtonImage.setTexture(subButton);

		sf::Texture invButton;
		sf::Sprite invButtonImage;
		if (!invButton.loadFromFile("inverse.png"))
			std::cout << "Can't find the image" << std::endl;
		invButtonImage.setPosition(800, 500);

		float invButtonWidth = invButtonImage.getLocalBounds().width;
		float invButtonHeight = invButtonImage.getLocalBounds().height;
		invButtonImage.setTexture(invButton);


		sf::Texture userButton;
		sf::Sprite userButtonImage;
		if (!userButton.loadFromFile("user.png"))
			std::cout << "Can't find the image" << std::endl;
		userButtonImage.setPosition(800, 500);

		float userButtonWidth = userButtonImage.getLocalBounds().width;
		float userButtonHeight = userButtonImage.getLocalBounds().height;
		userButtonImage.setTexture(userButton);

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

				case sf::Event::MouseMoved:
				{
					sf::Vector2i mousePos = sf::Mouse::getPosition(window);
					sf::Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
					if (addButtonImage.getGlobalBounds().contains(mousePosF))
					{
						addButtonImage.setColor(sf::Color(250, 20, 20));
					}else if (multButtonImage.getGlobalBounds().contains(mousePosF))
					{
						multButtonImage.setColor(sf::Color(250, 20, 20));
					}else if (subButtonImage.getGlobalBounds().contains(mousePosF))
					{
						subButtonImage.setColor(sf::Color(250, 20, 20));
					}
					else if (invButtonImage.getGlobalBounds().contains(mousePosF))
					{
					invButtonImage.setColor(sf::Color(250, 20, 20));
					}
					else if (backButtonImage.getGlobalBounds().contains(mousePosF))
					{
						backButtonImage.setColor(sf::Color(250, 20, 20));
					}
					else if (infoButtonImage.getGlobalBounds().contains(mousePosF))
					{
						infoButtonImage.setColor(sf::Color(250, 20, 20));
					}
					else if (userButtonImage.getGlobalBounds().contains(mousePosF))
					{
						userButtonImage.setColor(sf::Color(250, 20, 20));
					}
					else
					{
						addButtonImage.setColor(sf::Color(255, 255, 255));
						multButtonImage.setColor(sf::Color(255, 255, 255));
						subButtonImage.setColor(sf::Color(255, 255, 255));
						invButtonImage.setColor(sf::Color(255, 255, 255));
						backButtonImage.setColor(sf::Color(255, 255, 255));
						infoButtonImage.setColor(sf::Color(255, 255, 255));
						userButtonImage.setColor(sf::Color(255, 255, 255));
					}
				}
				break;
				

				case sf::Event::MouseButtonPressed:
				{
					if (op == false) {
						
						s = " ";
						s1 = " ";
						s2 = " ";
						sf::Vector2i mousePos = sf::Mouse::getPosition(window);
						sf::Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));




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
						std::vector<std::vector<int> > vector2 = m2->Linked2Vector(m1Rows, m1Cols, m2Rows, m2Cols, "Matrix 2");
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
						if (addButtonImage.getGlobalBounds().contains(mousePosF))
						{
							m3->addMatrix(m1->head, m2->head);
							op = true;
						}
						else if (multButtonImage.getGlobalBounds().contains(mousePosF))
						{
							m3->multiplyMatrix(m1->head, m2->head, m1Rows, m2Cols, m2Cols);
							op = true;
						}
						else if (subButtonImage.getGlobalBounds().contains(mousePosF))
						{
							m3->subtractMatrix(m1->head, m2->head);
							op = true;
						}
						else if (invButtonImage.getGlobalBounds().contains(mousePosF))
						{
							std::cout << "not here yet";
							op = true;
						}
						else if (backButtonImage.getGlobalBounds().contains(mousePosF))
						{
							//op = false;
							infoscreen = false;
						}
						else if (infoButtonImage.getGlobalBounds().contains(mousePosF))
						{
							infoscreen = true;
						}
						else if (userButtonImage.getGlobalBounds().contains(mousePosF))
						{
							inputscreen = true;

						}
						// adding the matricies and storing them into m3




						// make m3 into vector 
						std::vector<std::vector<int>> vector3 = m3->Linked2Vector(m1Rows, m1Cols, m2Rows, m2Cols, "Multiplication");

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
						
					}
					
					
				}
				break;
				// we can create different events for different keys pressed which will give us a way for user 
				// to choose what operation they want


					// if they close the window, close the window and break out of loop
				case sf::Event::Closed:
					window.close();
					break;
				
				 
				}
				
				
			}

			// .clear will clear the window 
			// .setposition will put our object at a specific cooridnate
			// draw will put the object on screen 
			// display will show us the window

			window.clear(sf::Color::White);

		

			if (op == true) {

				window.draw(backgroundImage);
				text.setPosition(10, 200);
				text4.setPosition(175, 250);
				text5.setPosition(600, 250);
				text1.setPosition(350, 200);
				text2.setPosition(700, 200);

				window.draw(text);
				window.draw(text1);
 				window.draw(text2);
			
				window.draw(text4);
				window.draw(text5);
				window.display();

			}
			else if (op == false && infoscreen == false) {

				window.draw(backgroundImage);
				s3 = "hello! please select an operation!";
				text3.setString(s3);
				text3.setPosition(600, 200);
				window.draw(text3);
				window.draw(addButtonImage);
				window.draw(multButtonImage);
				window.draw(invButtonImage);
				window.draw(subButtonImage);
				window.draw(infoButtonImage);
				window.display();

			}
			else if (infoscreen == true && op == false) {
				
				window.draw(backgroundImage);
				window.draw(backButtonImage);
				window.draw(infotext);
				window.display();
				
			}
			else if (inputscreen == true && op == false) {

				window.draw(backgroundImage);
				window.draw(userButtonImage);
				//window.draw(infotext);
				window.display();

			}
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
