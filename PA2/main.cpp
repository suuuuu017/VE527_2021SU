#include <iostream>
#include <fstream>
#include <sstream>

#include "cubelist.h"

class tooFewArgument{};

int main(int argc, char * argv[]){
    if(argc < 2 || argc > 2){
        throw tooFewArgument();
    }

    std::string filePath = argv[1];

    std::ifstream inputFile;
    inputFile.open(filePath);

    std::string line;

    int cubelength = 0;

    while(inputFile){
        getline(inputFile, line);
        if(inputFile){
            std::cout << line << std::endl;
            std::stringstream instr(line);
            instr >> cubelength;
        }
        break;
    }

    CubeList cubelist(cubelength);

    std::cout << cubelist.readCubeLength();

    inputFile.close();

}