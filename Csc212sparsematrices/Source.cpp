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


	std::vector<std::vector<int>> userm1;
	

    std::string file1 = argv[1];
	std::string file2 = argv[2];
	
	//the row and col count of m1 and m2
	int m1Rows, m2Rows, m1Cols, m2Cols;

	LinkedMatrix* m1 = ReadFile(file1, m1Rows, m1Cols);
	LinkedMatrix* m2 = ReadFile(file2, m2Rows, m2Cols);

	 LinkedMatrix* m3 = new LinkedMatrix(); //for addition
	//LinkedMatrix* m4 = new LinkedMatrix(); //for multiplication
	//LinkedMatrix* m5 = new LinkedMatrix(); //for subtraction
	LinkedMatrix *m6 = new LinkedMatrix(); //for inverse

	//m3->addMatrix(m1->head, m2->head); //add 
	//m4->multiplyMatrix(m1->head, m2->head, m1Rows, m2Cols, m1Cols); //multiply
	//m5->subtractMatrix(m1->head, m2->head); //subtract
//	m6->inverseMatrix(m1->head, m1Rows, m1Cols); //inverse
	
	
	//Print linked list output 
	// m1->print(m1->head, "Matrix 1");	
	// m2->print(m2->head, "Matrix 2");	
	// m3->print(m3->head, "Addition");	
	// m4->print(m4->head, "Multiplication");	
	// m5->print(m5->head, "Subtraction");
	//->print(m6->head, "Inverse");


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
		sf::String m1text;
		sf::Text m1Text(m1text, font, 25);
		m1Text.setFillColor(sf::Color::Black);

		// creating a text variable named text2
		sf::String m2text;
		sf::Text m2Text(m2text, font, 25);
		m2Text.setFillColor(sf::Color::Black);

		//// creating a text variable named text 3
		sf::String m3text;
		sf::Text m3Text(m3text, font, 25);
		m3Text.setFillColor(sf::Color::Black);


		sf::String hello;
		sf::Text helloText(hello, font, 60);
		helloText.setFillColor(sf::Color::Black);
		helloText.setStyle(sf::Text::Bold | sf::Text::Underlined);
		   
		hello = "Hello! Welcome to the sparse matrix calculator!";
		helloText.setString(hello);
		helloText.setPosition(80, 170);

		sf::String errort;
		sf::Text errorText(errort, font, 50);
		errorText.setFillColor(sf::Color::Red);
		errorText.setStyle(sf::Text::Bold);

		errort = "You have encountered an error.\nError: Matrix1 rows must equal Martrix2 columns.\nPlease fix inputs.";
		errorText.setString(errort);
		errorText.setPosition(200, 300);

		sf::String oper;
		sf::Text operText(oper, font, 60);
		operText.setFillColor(sf::Color::Black);
		operText.setStyle(sf::Text::Bold | sf::Text::Underlined);

		oper = "Please select an operation.";
		operText.setString(oper);
		operText.setPosition(375, 170);

		sf::String form;
		sf::Text formText(form, font, 20);
		formText.setFillColor(sf::Color::Black);
		

		form = "Format: Matrix1 operation Matrix2 = Resulting matrix";
		formText.setString(form);
		formText.setPosition(25, 700);

		sf::String type;
		sf::Text typeText(type, font, 40);
		typeText.setFillColor(sf::Color::Black);
		typeText.setStyle(sf::Text::Bold | sf::Text::Underlined);
		typeText.setPosition(650, 50);

		sf::String desc;
		sf::Text descText(desc, font, 25);
		descText.setFillColor(sf::Color::Black);


		

		desc = "- This program takes two sparse matricies read from files and performs mathematical operations on them. \n";
		desc += "- For more information please click 'more info' below. \n \n \n";
		desc += "- Developers: Mathew Ferreira, Amoy Scott, Emily Gautreaux, Whitney Schoellerman";
		descText.setString(desc);
		descText.setPosition(80, 300);

		sf::String ex;
		sf::Text exText(ex, font, 20);
		exText.setFillColor(sf::Color::Black);
		
		ex = "Please press the Escape key to exit.";
	
		exText.setString(ex);
		exText.setPosition(1050,700);

	

		sf::String sub;
		sf::Text subText(sub, font, 90);
		subText.setFillColor(sf::Color::Black);
		subText.setStyle(sf::Text::Bold);
		subText.setPosition(400, 250);

		sf::String s5;
		sf::Text text5(s5, font, 90);
		text5.setFillColor(sf::Color::Black);
		text5.setStyle(sf::Text::Bold);
		s5 = "=";
		text5.setString(s5);
		text5.setPosition(950, 250);


		sf::String info;
		sf::Text infotext(info, font, 25);
		infotext.setFillColor(sf::Color::Black);
		info = "This program takes in input of two sparse matricies and uses linked lists to do mathematical operations on them";
		info += "\nYou can perform an operation by left clicking an operation type. Then click 'Calculate'.\n";
		info += "Only one operation per execution of the program is possible and input sizes for a matrix is limited to 12x12.\n";
		info += "This perform operations such as add, multiply, subtract or inverse multiply,";
		info += " of the matrices in their linked list \nform with only non zero values.";
		info += "The result should consist of a sparse matrix, obtained by operating the two input matrices.\n";
		info += "In order for multiplication operations to execute sucessfully please ensure that number of rows of Matrix1.txt\n";
		info += "is equivelent to the number of columns in Matrix2.txt.";
		info += "\n \n \n \n \nExample operation where M1 = Matrix1.txt, M2 = Matrix2.txt and M3 = Resulting matrix after addition.";
		info += "\nM1+M2=M3:";
		infotext.setString(info);
		infotext.setPosition(50, 90);

		bool op = false;
		bool inputscreen = false;
		bool infoscreen = false;
		bool show = false;
		bool showm3 = false;
		bool error = false;
		bool done = false;
		
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
		backButtonImage.setPosition(25, 25);

		float backButtonWidth = backButtonImage.getLocalBounds().width;
		float backButtonHeight = backButtonImage.getLocalBounds().height;
		backButtonImage.setTexture(backButton);

		sf::Texture calcButton;
		sf::Sprite calcButtonImage;
		if (!calcButton.loadFromFile("calc.png"))
			std::cout << "Can't find the image" << std::endl;
		calcButtonImage.setPosition(600, 800);

		float calcButtonWidth = calcButtonImage.getLocalBounds().width;
		float calcButtonHeight = calcButtonImage.getLocalBounds().height;
		calcButtonImage.setTexture(calcButton);

		sf::Texture addButton;
		sf::Sprite addButtonImage;
		if (!addButton.loadFromFile("add.png"))
			std::cout << "Can't find the image" << std::endl;
		addButtonImage.setPosition(100, 600);

		float addButtonWidth = addButtonImage.getLocalBounds().width;
		float addButtonHeight = addButtonImage.getLocalBounds().height;
		addButtonImage.setTexture(addButton);

		sf::Texture multButton;
		sf::Sprite multButtonImage;
		if (!multButton.loadFromFile("multiply.png"))
			std::cout << "Can't find the image" << std::endl;
		multButtonImage.setPosition(750, 600);

		float multButtonWidth = multButtonImage.getLocalBounds().width;
		float multButtonHeight = multButtonImage.getLocalBounds().height;
		multButtonImage.setTexture(multButton);

		sf::Texture exaddButton;
		sf::Sprite exaddButtonImage;
		if (!exaddButton.loadFromFile("example.png"))
			std::cout << "Can't find the image" << std::endl;
		exaddButtonImage.setPosition(300, 500);
		exaddButtonImage.setTexture(exaddButton);

		sf::Texture subButton;
		sf::Sprite subButtonImage;
		if (!subButton.loadFromFile("subtract.png"))
			std::cout << "Can't find the image" << std::endl;
		subButtonImage.setPosition(375, 600);

		float subButtonWidth = subButtonImage.getLocalBounds().width;
		float subButtonHeight = subButtonImage.getLocalBounds().height;
		subButtonImage.setTexture(subButton);


		sf::Texture infoButton;
		sf::Sprite infoButtonImage;
		if (!infoButton.loadFromFile("info.png"))
			std::cout << "Can't find the image" << std::endl;
		infoButtonImage.setPosition(100, 800);

		float infoButtonWidth = infoButtonImage.getLocalBounds().width;
		float infoButtonHeight = infoButtonImage.getLocalBounds().height;
		infoButtonImage.setTexture(infoButton);

		sf::Texture nextButton;
		sf::Sprite nextButtonImage;
		if (!nextButton.loadFromFile("next.png"))
			std::cout << "Can't find the image" << std::endl;
		nextButtonImage.setPosition(1100, 800);

		float nextButtonWidth = nextButtonImage.getLocalBounds().width;
		float nextButtonHeight = nextButtonImage.getLocalBounds().height;
		nextButtonImage.setTexture(nextButton);

		sf::Texture invButton;
		sf::Sprite invButtonImage;
		if (!invButton.loadFromFile("inverse.png"))
			std::cout << "Can't find the image" << std::endl;
		invButtonImage.setPosition(1125, 600);

		float invButtonWidth = invButtonImage.getLocalBounds().width;
		float invButtonHeight = invButtonImage.getLocalBounds().height;
		invButtonImage.setTexture(invButton);

		sf::Texture goButton;
		sf::Sprite goButtonImage;
		if (!goButton.loadFromFile("go.png"))
			std::cout << "Can't find the image" << std::endl;
		goButtonImage.setPosition(100, 500);

		float goButtonWidth = goButtonImage.getLocalBounds().width;
		float goButtonHeight = goButtonImage.getLocalBounds().height;
		goButtonImage.setTexture(goButton);

	

		

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
					else if (goButtonImage.getGlobalBounds().contains(mousePosF))
					{
						goButtonImage.setColor(sf::Color(250, 20, 20));
					}
					else if (nextButtonImage.getGlobalBounds().contains(mousePosF))
					{
						nextButtonImage.setColor(sf::Color(250, 20, 20));
					}
					else if (calcButtonImage.getGlobalBounds().contains(mousePosF))
					{
						calcButtonImage.setColor(sf::Color(250, 20, 20));
					}
					
				
					else
					{
						addButtonImage.setColor(sf::Color(255, 255, 255));
						multButtonImage.setColor(sf::Color(255, 255, 255));
						subButtonImage.setColor(sf::Color(255, 255, 255));
						invButtonImage.setColor(sf::Color(255, 255, 255));
						backButtonImage.setColor(sf::Color(255, 255, 255));
						infoButtonImage.setColor(sf::Color(255, 255, 255));
						goButtonImage.setColor(sf::Color(255, 255, 255));
						nextButtonImage.setColor(sf::Color(255, 255, 255));
						calcButtonImage.setColor(sf::Color(255, 255, 255));
						
						
					}
				}
				break;
				

				case sf::Event::MouseButtonPressed:
				{
					
						m1text = " ";
						m2text = " ";
						m3text = " ";
						sf::Vector2i mousePos = sf::Mouse::getPosition(window);
						sf::Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));



						if (op == false) {

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
									m1text += str + " ";
									//text.setString(s);
								}
								m1text += "\n";
								m1Text.setString(m1text);
							}
						}
						if (op == false) {

							// same as above but for m2 and text1 object
							std::vector<std::vector<int> > vector2 = m2->Linked2Vector(m1Rows, m1Cols, m2Rows, m2Cols, "Matrix 2");
							for (int i = 0; i < vector2.size(); i++) {

								for (int j = 0; j < vector2[i].size(); j++) {
									std::stringstream tt;
									std::string str;
									tt << vector2[i][j];
									tt >> str;
									m2text += str + " ";
									//text2.setString(s1);
								}
								m2text += "\n";
								m2Text.setString(m2text);
							}
						}
						if (addButtonImage.getGlobalBounds().contains(mousePosF)&& show == false && showm3 == false)
						{
							type = "Addition";
							typeText.setString(type);
							sub = "+";
							m3->addMatrix(m1->head, m2->head);
							show = true;
							op = false;
						}
						else if (multButtonImage.getGlobalBounds().contains(mousePosF) && show == false && showm3 == false)
						{
							type = "Multiplication";
							typeText.setString(type);
							sub = "X";
							error = m3->multiplyMatrix(m1->head, m2->head, m1Rows, m2Cols, m2Cols);
							show = true;
							op = false;
						}
						else if (subButtonImage.getGlobalBounds().contains(mousePosF) && show == false && showm3 == false)
						{
							type = "Subtraction";
							typeText.setString(type);
							sub = "-";
							m3->subtractMatrix(m1->head, m2->head);
							show = true;
							op = false;
						}
						else if (invButtonImage.getGlobalBounds().contains(mousePosF) && show == false && showm3 == false)
						{
							type = "Inverse";
							typeText.setString(type);
							sub = "Inverse";
							subText.setCharacterSize(25);
							show = true;
							op = false;
						}
						else if (backButtonImage.getGlobalBounds().contains(mousePosF))
						{
							op = false;
							infoscreen = false;
						}
						else if (infoButtonImage.getGlobalBounds().contains(mousePosF))
						{
							infoscreen = true;
						}
						else if (nextButtonImage.getGlobalBounds().contains(mousePosF))
						{
							op = true;
						}
						else if (calcButtonImage.getGlobalBounds().contains(mousePosF))
						{
							showm3 = true;
						}
						
						else if (goButtonImage.getGlobalBounds().contains(mousePosF))
						{
							
							
							show = true;
							op = false;
							
						}
						
					
						// adding the matricies and storing them into m3


						if (op == false) {


							// make m3 into vector 
							std::vector<std::vector<int>> vector3 = m3->Linked2Vector(m1Rows, m1Cols, m2Rows, m2Cols, "Multiplication");

							//same as above but for m3 and text2 object
							for (int i = 0; i < vector3.size(); i++) {

								for (int j = 0; j < vector3[i].size(); j++) {
									std::stringstream tt;
									std::string str;
									tt << vector3[i][j];
									tt >> str;
									m3text += str + " ";
									
								}
								m3text += "\n";
								m3Text.setString(m3text);

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
				case sf::Event::KeyPressed:
					if (event.key.code == sf::Keyboard::Escape)
					{

						window.close();
						break;
					}
				 
				}
				
				
			}

			// .clear will clear the window 
			// .setposition will put our object at a specific cooridnate
			// draw will put the object on screen 
			// display will show us the window

			//window.clear();

			

			if (op == true && done == false) {


				window.clear();
				window.draw(backgroundImage);
				window.draw(operText);
				window.draw(addButtonImage);
				window.draw(multButtonImage);
				window.draw(invButtonImage);
				window.draw(subButtonImage);

				window.display();




			}
			else if (show == true && op == false && done == false) {
				window.clear();
				window.draw(backgroundImage);
				subText.setString(sub);
				m1Text.setPosition(75, 200);

				//text5.setPosition(600, 250);
				m2Text.setPosition(575, 200);
				m3Text.setPosition(1100, 200);
				window.draw(formText);

				window.draw(m1Text);
				window.draw(m2Text);
				window.draw(calcButtonImage);
				window.draw(typeText);
				window.draw(subText);
				window.draw(text5);
				if (showm3) {
					if (error) {


						window.clear();
						window.draw(backgroundImage);
						window.draw(errorText);

					}
					else {
						done = true;
						window.draw(m3Text);
						window.draw(exText);
						
					}

				}


				window.display();
			}

			else if (infoscreen == true && op == false && done == false) {

				window.clear();
				window.draw(backgroundImage);
				window.draw(backButtonImage);
				window.draw(infotext);
				window.draw(exaddButtonImage);
				window.display();

			}

			else if (op == false && infoscreen == false && done == false) {
				window.clear();
				window.draw(backgroundImage);
				window.draw(infoButtonImage);
				window.draw(helloText);
				window.draw(descText);
				window.draw(nextButtonImage);
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
