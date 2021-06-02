#include "triangledata.h"
#include <iostream>

using namespace std;

TriangleData::TriangleData(double legAFeet, double legBFeet)
        : _legAFeet(legAFeet)
        , _legBFeet(legBFeet)
{
}

TriangleData::~TriangleData()
{
}

double TriangleData::getLegLengthA(UnitType type) const
{
    return convert(_legAFeet, type);
}

double TriangleData::getLegLengthB(UnitType type) const
{
    return convert(_legBFeet, type);
}

double TriangleData::getHypotenuseLength(UnitType type) const
{
    return convert(_hypotenuseLength, type);
}

void TriangleData::setHypotenuseLength(double& hypotenuseLength)
{
    _hypotenuseLength = hypotenuseLength;
}

bool TriangleData::operator< (const TriangleData& comparison) const
{
    return (comparison.getHypotenuseLength(UnitType::Feet) > _hypotenuseLength);
}
    
double TriangleData::convert(double value, UnitType type) const
{
    double result{0};

    switch(type)
    {
        case UnitType::Feet:
            result = value;
            break;
        case UnitType::Meters:
            result = value * CONVERSION_KONST;
            break;
        default:
            cout << "Unknown unit type!";
            break;
    }
        
    return result;
}




