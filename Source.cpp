#include "LinkedMatrix.h"
#include "Node.h"
#include<fstream>
#include<sstream>
#include <iostream>
#include<vector>
#include <SFML/Graphics.hpp>


//function declarations
LinkedMatrix* ReadFile(std::string fileName, int& rows, int& cols);
void PrintVec(std::vector<std::vector<int> > vector);


//This function reads given text files os sparse matrices and creates a Linked Matrix
LinkedMatrix* ReadFile(std::string fileName, int& rows, int& cols) {
	int rowCount = 0, colCount = 0; //Counters to keep track of rows and columns
	std::ifstream inFile(fileName);
	std::string line;
	//create a new LinkedMatrix
	LinkedMatrix* matrix = new LinkedMatrix();

	//while file still has additional lines, keep reading lines
	while (getline(inFile, line)) {
		std::istringstream sstream(line);
		double num;
		colCount = 0;
		while (sstream >> num) {
			if (num != 0) {
				//if element is not zero add to linkedMatrix
				matrix->append(rowCount, colCount, num);
				//std::cout << "Row:" << rowCount << " Col: "<< colCount << " Value:"<< num << std::endl;
			}
			//increment column count
			colCount++;
		}
		//increment rowcount
		rowCount++;
	}
	//update rows and col parameters of matrix
	rows = rowCount;
	cols = colCount;
	//close file and return the new LinkedMatrix list
	inFile.close();
	return matrix;
}


//Program command line input format
//arguments ./prog matrix1.txt matrix2.txt
//This program takes in two text files of sparse matrices that will be used to perform Matrix Math operations
int main(int argc, char* argv[]) {


	std::vector<std::vector<int>> userm1;

	// load in readfiles
	std::string file1 = argv[1];
	std::string file2 = argv[2];

	//the row and col count of m1 and m2
	int m1Rows, m2Rows, m1Cols, m2Cols;

	//input matricies
	LinkedMatrix* m1 = ReadFile(file1, m1Rows, m1Cols);
	LinkedMatrix* m2 = ReadFile(file2, m2Rows, m2Cols);
	//output matrix 
	LinkedMatrix* m3 = new LinkedMatrix(); //for addition
  

	sf::RenderWindow window(sf::VideoMode(1500, 900), "Sparse Matrix Operations!");



	// font object 
	sf::Font font;

	//Load and check the availability of the font file
	if (!font.loadFromFile("buttons/font.ttf"))
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

	// text obj to meet user
	sf::String hello;
	sf::Text helloText(hello, font, 60);
	helloText.setFillColor(sf::Color::Black);
	helloText.setStyle(sf::Text::Bold | sf::Text::Underlined);
	hello = "Hello! Welcome to the sparse matrix calculator!";
	helloText.setString(hello);
	helloText.setPosition(80, 170);

	// multiplication error
	sf::String errort;
	sf::Text errorText(errort, font, 50);
	errorText.setFillColor(sf::Color::Red);
	errorText.setStyle(sf::Text::Bold);
	errort = "You have encountered an error.\nError: Matrix1 rows must equal Martrix2 columns.\nPlease fix inputs.";
	errorText.setString(errort);
	errorText.setPosition(200, 300);

	// command for operation 
	sf::String oper;
	sf::Text operText(oper, font, 60);
	operText.setFillColor(sf::Color::Black);
	operText.setStyle(sf::Text::Bold | sf::Text::Underlined);
	oper = "Please select an operation.";
	operText.setString(oper);
	operText.setPosition(375, 170);

	//format of operation
	sf::String form;
	sf::Text formText(form, font, 20);
	formText.setFillColor(sf::Color::Black);
	form = "Format: Matrix1 operation Matrix2 = Resulting matrix";
	formText.setString(form);
	formText.setPosition(25, 700);

	// type of operation
	sf::String type;
	sf::Text typeText(type, font, 40);
	typeText.setFillColor(sf::Color::Black);
	typeText.setStyle(sf::Text::Bold | sf::Text::Underlined);
	typeText.setPosition(650, 50);

	//program description
	sf::String desc;
	sf::Text descText(desc, font, 25);
	descText.setFillColor(sf::Color::Black);
	desc = "- This program takes two sparse matricies read from files and performs mathematical operations on them. \n";
	desc += "- For more information please click 'more info' below. \n \n \n";
	desc += "- Developers: Mathew Ferreira, Amoy Scott, Emily Gautreaux, Whitney Schoellerman";
	descText.setString(desc);
	descText.setPosition(80, 300);

	// exit command
	sf::String ex;
	sf::Text exText(ex, font, 33);
	exText.setFillColor(sf::Color::Black);
	ex = "Please press the Escape key to exit.\nOr press the Enter key to perform a new operation.";
	exText.setString(ex);
	exText.setPosition(700, 650);

	// type of operatio n
	sf::String sub;
	sf::Text subText(sub, font, 100);
	subText.setFillColor(sf::Color::Black);
	subText.setStyle(sf::Text::Bold);
	subText.setPosition(380, 250);
	
	// equal sign 
	sf::String s5;
	sf::Text text5(s5, font, 90);
	text5.setFillColor(sf::Color::Black);
	text5.setStyle(sf::Text::Bold);
	s5 = "=";
	text5.setString(s5);
	text5.setPosition(950, 250);

	// more info on project
	sf::String info;
	sf::Text infotext(info, font, 25);
	infotext.setFillColor(sf::Color::Black);
	info = "This program takes in input of two sparse matricies and uses linked lists to do mathematical operations on them";
	info += "\nYou can perform an operation by left clicking an operation type. Then click 'Calculate'.\n";
	info += "Only one set of matricies may be used per execution of the program and input sizes for a matrix is limited to 12x12.\n";
	info += "To multiply, ensure that the first command line arguments' files are equal to the second command line arguements columns.\n";
	info += "To find the inverse of a matrix, please only provide inputs of 1X1, 2X2 and 3X3 for the first command line arguement only.\n";
	info += "The result should consist of a sparse matrix, obtained by operating the two input matrices.\n";
	info += "\n \n \n \n \nExample operation where M1 = Matrix1.txt, M2 = Matrix2.txt and M3 = Resulting matrix after addition.";
	info += "\nM1+M2=M3:";
	infotext.setString(info);
	infotext.setPosition(50, 90);

	// menu state varibles 
	bool opperationScreen = false; // if an operation has been picked
	bool inputscreen = false; // if on screen to pick operation
	bool infoscreen = false; // more info screen
	bool show = false; // show the operators 
	bool showm3 = false; // show resulting matrix
	bool error = false; // error screen 
	bool done = false; // if an operation has been conducted 
	bool inversecheck = false; // checking if operation is inverse because different screen 
	sf::Texture background;
	sf::Sprite backgroundImage;

	// load in blue photo 
	if (!background.loadFromFile("buttons/background.png"))
		std::cout << "Error: Could not display " << std::endl;
	backgroundImage.setTexture(background);
	backgroundImage.setScale(10000, 1000);

	// back button
	sf::Texture backButton;
	sf::Sprite backButtonImage;
	if (!backButton.loadFromFile("buttons/back.png"))
		std::cout << "Can't find the image" << std::endl;
	backButtonImage.setPosition(25, 25);

	float backButtonWidth = backButtonImage.getLocalBounds().width;
	float backButtonHeight = backButtonImage.getLocalBounds().height;
	backButtonImage.setTexture(backButton);

	// calculate button 
	sf::Texture calcButton;
	sf::Sprite calcButtonImage;
	if (!calcButton.loadFromFile("buttons/calc.png"))
		std::cout << "Can't find the image" << std::endl;
	calcButtonImage.setPosition(600, 800);

	float calcButtonWidth = calcButtonImage.getLocalBounds().width;
	float calcButtonHeight = calcButtonImage.getLocalBounds().height;
	calcButtonImage.setTexture(calcButton);
	
	// add button
	sf::Texture addButton;
	sf::Sprite addButtonImage;
	if (!addButton.loadFromFile("buttons/add.png"))
		std::cout << "Can't find the image" << std::endl;
	addButtonImage.setPosition(100, 600);

	float addButtonWidth = addButtonImage.getLocalBounds().width;
	float addButtonHeight = addButtonImage.getLocalBounds().height;
	addButtonImage.setTexture(addButton);
	
	// multiply option
	sf::Texture multButton;
	sf::Sprite multButtonImage;
	if (!multButton.loadFromFile("buttons/multiply.png"))
		std::cout << "Can't find the image" << std::endl;
	multButtonImage.setPosition(750, 600);

	float multButtonWidth = multButtonImage.getLocalBounds().width;
	float multButtonHeight = multButtonImage.getLocalBounds().height;
	multButtonImage.setTexture(multButton);

	// exsample image
	sf::Texture exaddButton;
	sf::Sprite exaddButtonImage;
	if (!exaddButton.loadFromFile("buttons/example.png"))
		std::cout << "Can't find the image" << std::endl;
	exaddButtonImage.setPosition(300, 500);
	exaddButtonImage.setTexture(exaddButton);

	// subtract button
	sf::Texture subButton;
	sf::Sprite subButtonImage;
	if (!subButton.loadFromFile("buttons/subtract.png"))
		std::cout << "Can't find the image" << std::endl;
	subButtonImage.setPosition(375, 600);

	float subButtonWidth = subButtonImage.getLocalBounds().width;
	float subButtonHeight = subButtonImage.getLocalBounds().height;
	subButtonImage.setTexture(subButton);

	// more info button
	sf::Texture infoButton;
	sf::Sprite infoButtonImage;
	if (!infoButton.loadFromFile("buttons/info.png"))
		std::cout << "Can't find the image" << std::endl;
	infoButtonImage.setPosition(100, 800);

	float infoButtonWidth = infoButtonImage.getLocalBounds().width;
	float infoButtonHeight = infoButtonImage.getLocalBounds().height;
	infoButtonImage.setTexture(infoButton);

	// next page button 
	sf::Texture nextButton;
	sf::Sprite nextButtonImage;
	if (!nextButton.loadFromFile("buttons/next.png"))
		std::cout << "Can't find the image" << std::endl;
	nextButtonImage.setPosition(1100, 800);

	float nextButtonWidth = nextButtonImage.getLocalBounds().width;
	float nextButtonHeight = nextButtonImage.getLocalBounds().height;
	nextButtonImage.setTexture(nextButton);

	// inverse selection button 
	sf::Texture invButton;
	sf::Sprite invButtonImage;
	if (!invButton.loadFromFile("buttons/inverse.png"))
		std::cout << "Can't find the image" << std::endl;
	invButtonImage.setPosition(1125, 600);

	float invButtonWidth = invButtonImage.getLocalBounds().width;
	float invButtonHeight = invButtonImage.getLocalBounds().height;
	invButtonImage.setTexture(invButton);

	// might dont use 
	sf::Texture goButton;
	sf::Sprite goButtonImage;
	if (!goButton.loadFromFile("buttons/go.png"))
		std::cout << "Can't find the image" << std::endl;
	goButtonImage.setPosition(100, 500);

	float goButtonWidth = goButtonImage.getLocalBounds().width;
	float goButtonHeight = goButtonImage.getLocalBounds().height;
	goButtonImage.setTexture(goButton);

	// resulting matrix vector for output
	std::vector<std::vector<double>> vector3;

	

	// making sure window is open 
	while (window.isOpen())


	{
		// an event object that will store any type of event that occurs, in our case,
		// an event will be holding user input from keyboard 
		sf::Event event;
		// while there is an event that has occured....
		while (window.pollEvent(event))
		{

		//	m1 = ReadFile(file1, m1Rows, m1Cols);
		//	m2 = ReadFile(file2, m2Rows, m2Cols);

			// process each event by type 
			switch (event.type) {

			case sf::Event::MouseMoved:
			{	
				// obtain mouse coordinates 
				sf::Vector2i mousePos = sf::Mouse::getPosition(window);
				sf::Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));

				// all of these staements will see if the mouse coordinates are within the bounds of a 
				// given button and if so, turn button red. 
				if (addButtonImage.getGlobalBounds().contains(mousePosF))
				{
					addButtonImage.setColor(sf::Color(250, 20, 20));
				}
				else if (multButtonImage.getGlobalBounds().contains(mousePosF))
				{
					multButtonImage.setColor(sf::Color(250, 20, 20));
				}
				else if (subButtonImage.getGlobalBounds().contains(mousePosF))
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

				// turn button back to normal color 
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

			// mouse click event
			case sf::Event::MouseButtonPressed:
			{
				// reseting all strings and getting mouse coordinates again
				m1text = " ";
				m2text = " ";
				m3text = " ";
				std::string str = "";
				sf::Vector2i mousePos = sf::Mouse::getPosition(window);
				sf::Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));


				// turn first sprase matrix into vector for output
				if (opperationScreen == false) {

					// make m1 into vector 
					std::vector<std::vector<double>> vector;
					m1->Linked2Vector(m1Rows, m1Cols, m2Rows, m2Cols, vector, "Matrix 1");

					// this will take all values of m1 and append them into a string named "s"
					// it will then assign string s to the text varible using text.setstring
					for (int i = 0; i < vector.size(); i++) {

						for (int j = 0; j < vector[i].size(); j++) {
							std::stringstream ss;
							
							ss << vector[i][j];
							ss >> str;
							m1text += str + " ";
							
						}
						m1text += "\n";
						m1Text.setString(m1text);
					}
				}
				// turn second sprase matrix into vector for output
				if (opperationScreen == false) {

					// same as above but for m2 and text1 object
					std::vector<std::vector<double>> vector2;
					m2->Linked2Vector(m1Rows, m1Cols, m2Rows, m2Cols, vector2, "Matrix 2");
					for (int i = 0; i < vector2.size(); i++) {

						for (int j = 0; j < vector2[i].size(); j++) {
							std::stringstream tt;
							std::string str;
							tt << vector2[i][j];
							tt >> str;
							m2text += str + " ";
							
						}
						m2text += "\n";
						m2Text.setString(m2text);
					}
				}
				// if add button is mouse clicked 
				if (addButtonImage.getGlobalBounds().contains(mousePosF) && show == false && showm3 == false)
				{
					// set operation "icon"
					type = "Addition";
					typeText.setString(type);
					sub = "+";
					// do operation
					m3->addMatrix(m1->head, m2->head);
					show = true;
					opperationScreen = false;
					inversecheck = false;
					// clear out old stuff 
					vector3.clear();
					m3Text.setString("");
					
					if (opperationScreen == false) {
						// turn resulting matrix into a vector 
						m3->Linked2Vector(m1Rows, m1Cols, m2Rows, m2Cols, vector3, type);

						//fill a string with the martix values 
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
				// multiplication click 
				else if (multButtonImage.getGlobalBounds().contains(mousePosF) && show == false && showm3 == false)
				{
					type = "Multiplication";
					typeText.setString(type);
					sub = "X";
					error = m3->multiplyMatrix(m1->head, m2->head, m1Rows, m2Cols, m2Cols);
					show = true;
					opperationScreen = false;
					inversecheck = false;

					vector3.clear();
					m3Text.setString("");
				
					if (opperationScreen == false) {

						m3->Linked2Vector(m1Rows, m1Cols, m2Rows, m2Cols, vector3, type);

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
				// subtraction button 
				else if (subButtonImage.getGlobalBounds().contains(mousePosF) && show == false && showm3 == false)
				{
					type = "Subtraction";
					typeText.setString(type);
					sub = "-";
					m3->subtractMatrix(m1->head, m2->head);
					show = true;
					opperationScreen = false;
					vector3.clear();
					m3Text.setString("");
					inversecheck = false;
			
					if (opperationScreen == false) {

						m3->Linked2Vector(m1Rows, m1Cols, m2Rows, m2Cols, vector3, type);

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
				// inverse button 
				else if (invButtonImage.getGlobalBounds().contains(mousePosF) && show == false && showm3 == false)
				{			
					inversecheck = true;
					type = "Inverse";
					typeText.setString(type);
					sub = "Inverse";
					subText.setCharacterSize(25);
					show = true;
					error = m3->inverseMatrix(m1->head, m1Rows, m1Cols);
					opperationScreen = false;
					vector3.clear();
					m3Text.setString("");
					

					if (opperationScreen == false) {

						if(error == false)
							m3->Linked2Vector(m1Rows, m1Cols, m2Rows, m2Cols, vector3, type);

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
				// back button and update screens staet
				else if (backButtonImage.getGlobalBounds().contains(mousePosF))
				{
					opperationScreen = false;
					infoscreen = false;
				}
				// more info button and update screens state
				else if (infoButtonImage.getGlobalBounds().contains(mousePosF))
				{
					infoscreen = true;
				}
				// next button and update screen state
				else if (nextButtonImage.getGlobalBounds().contains(mousePosF))
				{
					opperationScreen = true;
				}
				// calcualte button and update screen state 
				else if (calcButtonImage.getGlobalBounds().contains(mousePosF))
				{
					showm3 = true;
				
				}
				// dunno yet
				else if (goButtonImage.getGlobalBounds().contains(mousePosF))
				{
					show = true;
					opperationScreen = false;
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
				// enter is pressed, reset state of program 
				if (event.key.code == sf::Keyboard::Enter) {
					
					opperationScreen = false;
					inputscreen = false;
					infoscreen = false;
					show = false;
					showm3 = false;
					error = false;
					done = false;
					m3->head->deleteList(&m3->head);
				}
			}
		}

		// .clear will clear the window 
		// .setposition will put our object at a specific cooridnate
		// draw will put the object on screen 
		// display will show us the window
		//window.clear();
		// screen for user to pick an opperation
		if (opperationScreen == true && done == false) {

			window.clear();
			window.draw(backgroundImage);
			window.draw(operText);
			window.draw(addButtonImage);
			window.draw(multButtonImage);
			window.draw(invButtonImage);
			window.draw(subButtonImage);
			window.display();
		}
		// screen for displaying results 
		else if (show == true && opperationScreen == false && done == false) {

			// screen for if we are doing inverse
			if (inversecheck) {

				window.clear();
				window.draw(backgroundImage);
				subText.setString(sub);
				subText.setPosition(550, 225);
				m1Text.setPosition(275, 225);

				text5.setPosition(770, 220);
				m3Text.setPosition(880, 225);
				window.draw(formText);

				window.draw(m1Text);
				window.draw(calcButtonImage);
				window.draw(typeText);
				window.draw(subText);
				window.draw(text5);
				// show result and check for errors 
				if (showm3) {
					if (error) {


						window.clear();
						window.draw(backgroundImage);
						window.draw(errorText);
						window.draw(exText);
						errorText.setString("Your matrix must only be: 1X1, 2X2 or 3X3.");
					}
					else {

						done = true;
						window.draw(m3Text);
						window.draw(exText);
					}
				}
				
			}
			// results screen for all operations besides inverse
			else {

				window.clear();
				window.draw(backgroundImage);
				subText.setString(sub);
				m1Text.setPosition(75, 225);
				subText.setPosition(400, 250);
				//text5.setPosition(600, 250);
				text5.setPosition(950, 250);
				m2Text.setPosition(575, 225);
				m3Text.setPosition(1100, 225);
				window.draw(formText);

				window.draw(m1Text);
				window.draw(m2Text);
				window.draw(calcButtonImage);
				window.draw(typeText);
				window.draw(subText);
				window.draw(text5);
				// show results and check for errors
				if (showm3) {
					if (error) {

						errorText.setString(errort);
						window.clear();
						window.draw(backgroundImage);
						window.draw(errorText);
						window.draw(exText);
					}
					else {

						done = true;
						window.draw(m3Text);
						window.draw(exText);
					}
				}
			}
			window.display();
		}
		// screen for more info
		else if (infoscreen == true && opperationScreen == false && done == false) {

			window.clear();
			window.draw(backgroundImage);
			window.draw(backButtonImage);
			window.draw(infotext);
			window.draw(exaddButtonImage);
			window.display();

		}
		// screen for first opening page 
		else if (opperationScreen == false && infoscreen == false && done == false) {
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
void PrintVec(std::vector<std::vector<int>> vector) {

	for (int i = 0; i < vector.size(); i++) {
		for (int j = 0; j < vector[i].size(); j++) {
			std::cout << vector[i][j] << " ";
		}
		std::cout << std::endl;
	}
}