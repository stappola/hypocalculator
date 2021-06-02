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
        TriangleData(double, double);
        ~TriangleData();
    // API
    public:
        double getLegLengthA(UnitType type) const;
        double getLegLengthB(UnitType type) const;
        double getHypotenuseLength(UnitType type) const;
        void setHypotenuseLength(double& hypotenuseLength);
        bool operator< (const TriangleData& comparison) const;
    // Helpers
    private:
        double convert(double value, UnitType type) const;
    // Data
    private:
        double _legAFeet{0};
        double _legBFeet{0};
        double _hypotenuseLength{0};
};



