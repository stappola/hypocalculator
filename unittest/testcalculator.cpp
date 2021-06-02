#include "hypocalculator.h"
#include <gtest/gtest.h>

/********************************************************************
 * Common test fixture for handling setup and teardown operations.
 ********************************************************************/
class HypoCalculatorFixture : public testing::Test
{
    public:
   
    HypoCalculatorFixture()
    {
    }

    /********************************************************************
    * Test teardown.
    ********************************************************************/
    virtual ~HypoCalculatorFixture()
    {
    }
};

// Demonstrate some basic assertions.
TEST(HypoCalculatorFixture, EmptyInput)
{
    HypoCalculator calculator("", "");
}