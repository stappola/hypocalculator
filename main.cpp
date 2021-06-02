#include <iostream>
#include <vector>
#include <stdio.h>
#include "hypocalculator.h"

using namespace std;


int main(int argc, char *argv[])
    {
    
    if(argc < 3)
    {
        cout << "Wrong number of arguments." << endl;
        return EXIT_FAILURE;
    }

    string inputFileName{argv[1]};
    string outputFileName{argv[2]};

    HypoCalculator calculator(inputFileName, outputFileName);
    
    if(calculator.readInput())
    {
        calculator.calculate();
        calculator.sort();
        calculator.storeResults();
    }
    
    return EXIT_SUCCESS;
    }

