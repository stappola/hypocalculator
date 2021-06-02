#include <iostream>
#include <vector>
#include <fstream>
#include "triangledata.h"

#pragma once

using namespace std;


class HypoCalculator
{
    // Constructors
    public:  
        HypoCalculator(const string& input, const string output);
        ~HypoCalculator();

    // Public API
    public:
        bool readInput();
        void calculate();
        void sort();
        void storeResults();
    
    // Private helpers
    private:
        int readInputData();
        void compileValidData();

    private:
        string _inputFile{""};
        string _outputFile{""};
        vector<pair<string, string> > legLengthsStr;
        vector<TriangleData> _results;
        ifstream _infile;

};



