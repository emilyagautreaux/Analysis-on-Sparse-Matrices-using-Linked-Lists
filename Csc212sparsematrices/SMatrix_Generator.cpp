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
        random = rand() % 100 + 1;
            if(random <= 70){
                outFile << "0 ";
            }
            else{
                randVal = rand() % 100 + 1;
                outFile << randVal << " ";
            }
        }
        outFile << std::endl;
    }
    return 0;
}