
#include <iostream>
#include <string.h>
#include <gtest/gtest.h>

class UnitTestEnvironment : public ::testing::Environment
{
public:

    // Override this to define how to set up the environment
    virtual void SetUp()
    {
    }

    // Override this to define how to tear down the environment
    virtual void TearDown()
    {
    }
};

class testCaseInitializer : public ::testing::EmptyTestEventListener
{
public:

    virtual void OnTestCaseStart(const ::testing::TestCase& tc)
    {
    }

    virtual void OnTestStart(const ::testing::TestInfo& ti)
    {    
    }

    virtual void OnTestEnd(const ::testing::TestInfo& ti)
    {
        std::cout << ti.result()->Passed(), "*** OUTPUT FROM FAILED TEST:\n";
    }

    virtual void OnTestProgramEnd(const ::testing::UnitTest& unit_test)
    {
    }
};

int main(int argc, char* argv[])
{
    ::testing::AddGlobalTestEnvironment(new UnitTestEnvironment());

    ::testing::InitGoogleTest(&argc, argv);

    // TODO: Take mocks into use
    // ::testing::InitGoogleMock(&argc, argv);

    ::testing::TestEventListeners& listeners =
          ::testing::UnitTest::GetInstance()->listeners();
    listeners.Append(new testCaseInitializer);

    return RUN_ALL_TESTS();
}
