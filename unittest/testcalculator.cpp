#include "hypocalculator.h"
#include <gtest/gtest.h>

static const char* DEFAULT_OUTPUT_FILE_NAME = "output.txt";

/********************************************************************
 * Common test fixture for setup, teardown & helper operations.
 ********************************************************************/
class HypoCalculatorFixture : public testing::Test
{
    public:
    
        HypoCalculatorFixture() {}
        virtual ~HypoCalculatorFixture() {}
        
    public:

        bool verifyOutputExists()
        {
            try
            {
                ifstream infile(DEFAULT_OUTPUT_FILE_NAME, ios::in | ios::ate);
                return !infile.fail();
            }
            catch(const std::exception& e)
            {
                std::cerr << "Exception when reading input file" << endl;
            }

            return false;
        }

        void runNormalSequence(HypoCalculator& calculator)
        {
            ASSERT_TRUE(calculator.readInput());
            EXPECT_NO_THROW(calculator.calculate());
            ASSERT_TRUE(calculator.sort());
            EXPECT_NO_THROW(calculator.storeResults());
            ASSERT_TRUE(verifyOutputExists());
        }
};

TEST_F(HypoCalculatorFixture, EmptyInputOnConstructor)
{
    // Input is not validated at construction time
    HypoCalculator calculator("", "");
}

TEST_F(HypoCalculatorFixture, EmptyInputReadFails)
{
    HypoCalculator calculator("", "");

    EXPECT_THROW(
    {
        try
        {
            calculator.readInput();
        }
        catch(const std::length_error& e)
        {
            EXPECT_STREQ("Invalid input data!", e.what());
            throw;
        }
    }, std::length_error);
}

TEST_F(HypoCalculatorFixture, NoProcessedDataOnOutput)
{
    HypoCalculator calculator("", "");

    EXPECT_THROW(
    {
        try
        {
            calculator.storeResults();
        }
        catch(const std::logic_error& e)
        {
            EXPECT_STREQ("No processed data to output!", e.what());
            throw;
        }
    }, std::logic_error);
}

TEST_F(HypoCalculatorFixture, NoProcessedDataOnCalculation)
{
    HypoCalculator calculator("", "");

    EXPECT_THROW(
    {
        try
        {
            calculator.calculate();
        }
        catch(const std::logic_error& e)
        {
            EXPECT_STREQ("No valid data to process!", e.what());
            throw;
        }
    }, std::logic_error);
}

TEST_F(HypoCalculatorFixture, InputDataOK)
{
    HypoCalculator calculator("../testdata/input1.txt", "output.txt");
    ASSERT_TRUE(calculator.readInput());
}

TEST_F(HypoCalculatorFixture, NormalSequence)
{
    HypoCalculator calculator("../testdata/input1.txt", DEFAULT_OUTPUT_FILE_NAME);
    runNormalSequence(calculator);
}

TEST_F(HypoCalculatorFixture, SortWrongState)
{
    HypoCalculator calculator("", "");
    ASSERT_FALSE(calculator.sort());
}