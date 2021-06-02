#include "hypocalculator.h"
#include <iostream>
#include <sstream>
#include <ctype.h>
#include <math.h>
#include <algorithm>

static const char* LEG_A      = "legA";
static const char* LEG_B      = "legB";
static const char* HYPOTENUSE = "hypotenuse";

HypoCalculator::HypoCalculator(const string& input, const string output)
    : _inputFile(input)
    , _outputFile(output)
{
    cout << "Input: " << _inputFile << " Output: " << _outputFile << endl;
}

HypoCalculator::~HypoCalculator()
{
}

void HypoCalculator::calculate()
{
    compileValidData();

    vector<TriangleData>::iterator legItr;
    for(legItr = _results.begin();legItr != _results.end();++legItr)
    {
        double a2 = pow(legItr->getLegLengthA(UnitType::Feet), 2);
        double b2 = pow(legItr->getLegLengthB(UnitType::Feet), 2);
        double hypotenuse = sqrt(a2 + b2);
        legItr->setHypotenuseLength(hypotenuse);
    }
}

void HypoCalculator::compileValidData()
{
    double legA{0};
    double legB{0};
    std::stringstream converterA;
    std::stringstream converterB;
    
    vector<pair<string, string> >::iterator legIterator;
    for(legIterator = legLengthsStr.begin();legIterator != legLengthsStr.end();++legIterator)
    {
        converterA.str(legIterator->first);
        converterB.str(legIterator->second);
        converterA >> legA;
        converterB >> legB;

        if(!converterA.fail() && !converterB.fail())
        {
            TriangleData resultData(legA, legB);
            _results.push_back(resultData);
        }

        converterA.clear();
        converterB.clear();
    }
}

void HypoCalculator::sort()
{
    std::sort (_results.begin(), _results.end());
}

void HypoCalculator::storeResults()
{
    ofstream outfile;

    try
    {
        outfile.open(_outputFile, ios::out | ios::ate);
        outfile << LEG_A << " " << LEG_B << " " << HYPOTENUSE << endl;

        vector<TriangleData>::iterator itr;
        for(itr = _results.begin();itr != _results.end();++itr)
        {
            outfile << itr->getLegLengthA(UnitType::Meters) << " "
                    << itr->getLegLengthB(UnitType::Meters) << " "
                    << itr->getHypotenuseLength(UnitType::Meters) << endl;
        }

        outfile.flush();
        outfile.close();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        cout << "Writing of output data failed" << endl;
    }
}

bool HypoCalculator::readInput()
{
    if(readInputData() == 0)
    {
        cout << "Reading of input data failed" << endl;
        return false;
    }
    else
    {
        string legA{""};
        string legB{""};

        try
        {
            while(!_infile.eof())
            {
                _infile >> legA >> legB;

                if(!_infile.bad() && !_infile.fail())
                {
                    legLengthsStr.push_back(make_pair(legA, legB));
                }
            }
        }
        catch(const std::exception& e)
        {
            cout << "Exception when reading" << endl;
            cout << "Leg A: " << legA << " Leg B: " << legB << endl;
            std::cerr << e.what() << '\n';
        }
    }

    _infile.close();
}

int HypoCalculator::readInputData()
{
    int fileSize{0};

    try
    {
        _infile.open(_inputFile, ios::in | ios::ate);
        fileSize = _infile.tellg();
        cout << "Input data size: " << fileSize << endl;
        _infile.seekg(0);
    }
    catch(const std::exception& e)
    {
        std::cerr << "Exception when reading input file" << endl;
    }

    return fileSize;
}




