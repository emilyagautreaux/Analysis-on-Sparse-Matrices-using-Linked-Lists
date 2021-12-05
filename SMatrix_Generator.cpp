/*
Creates a random sparse matrix inside a text file
with user specified row/col numbers and output filename
*/
#include <iostream>
#include <string>
#include <vector>
#include<fstream>
#include <cstdlib>

// input looks for number of desired rows, cols and outputfile name
//  ./prog row col outputFileName.txt
int main(int argc, char *argv[]){

    int rows = std::stoi(argv[1]),
        cols = std::stoi(argv[2]);
    std::string fName = argv[3];
    
    srand(time(NULL));

    std::ofstream outFile(fName);
    int random, randVal;

    for (int i=0; i<rows; i++){
        
        for(int j=0; j<cols; j++){
        //create random number from 1-100
        //if the generated number is <= 70 a zero value is placed in the element
        random = rand() % 100 + 1;
            if(random <= 70){
                outFile << "0 ";
            }
            //if the random number happens to be greater than 70
            //another random number between 1 and 100 is generated to be placed
            // in that element of the vector
            else{
                randVal = rand() % 100 + 1;
                outFile << randVal << " ";
            }
        }
        outFile << std::endl;
    }
    return 0;
}