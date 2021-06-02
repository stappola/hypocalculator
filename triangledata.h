#include <iostream>

#pragma once

using namespace std;

enum class UnitType : uint8_t
{
    Unknown = 0,
    Meters,
    Feet
};

static constexpr double CONVERSION_KONST = 0.3048;

class TriangleData
{
    // Constructors
    public:  
        TriangleData(double legAFeet, double legBFeet)
        : _legAFeet(legAFeet)
        , _legBFeet(legBFeet) {}
        ~TriangleData() {};
    public:

        double getLegLengthA(UnitType type) const
        {
            return convert(_legAFeet, type);
        }

        double getLegLengthB(UnitType type) const
        {
            return convert(_legBFeet, type);
        }

        double getHypotenuseLength(UnitType type) const
        {
            return convert(_hypotenuseLength, type);
        }

        void setHypotenuseLength(double& hypotenuseLength)
        {
            _hypotenuseLength = hypotenuseLength;
        }

        bool operator< (const TriangleData& comparison) const
        {
            return (comparison.getHypotenuseLength(UnitType::Feet) > _hypotenuseLength);
        }
    
    private:

        double convert(double value, UnitType type) const
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

    private:
        double _legAFeet{0};
        double _legBFeet{0};
        double _hypotenuseLength{0};
};



