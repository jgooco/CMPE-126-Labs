#include "gtest/gtest.h"
#include "expressionstream.h"

class Lab01Fixture : public ::testing::Test {
protected:
protected:
    virtual void TearDown() {
        delete stream1;
        delete stream2;
    }

    virtual void SetUp() {
        stream1=new expressionstream("1+2+3");
        stream2=new expressionstream("1   + 2 *4+(2*3)");
    }


public:
    expressionstream *stream1;
    expressionstream *stream2;
};


TEST(crashTest , constructorTest) {
    expressionstream stream1 ("1+2+3");
    expressionstream stream2 ("1   + 2 *4+(2*3)");
}


TEST_F(Lab01Fixture, basicTest) {
    EXPECT_EQ("1",stream1->get_next_int());
    EXPECT_EQ("2",stream1->get_next_int());
    EXPECT_EQ("3",stream1->get_next_int());

    EXPECT_EQ("+",stream1->get_next_op());
    EXPECT_EQ("+",stream1->get_next_op());
//todo: Get these tests to pass using the debugger
    EXPECT_EQ("1",stream2->get_next_int());
    EXPECT_EQ("2",stream2->get_next_int());
    EXPECT_EQ("4",stream2->get_next_int());
    EXPECT_EQ("2",stream2->get_next_int());
    EXPECT_EQ("3",stream2->get_next_int());

    EXPECT_EQ("+",stream2->get_next_op());
    EXPECT_EQ("*",stream2->get_next_op());
    EXPECT_EQ("+",stream2->get_next_op());
    EXPECT_EQ("(",stream2->get_next_op());
    EXPECT_EQ("*",stream2->get_next_op());
    EXPECT_EQ(")",stream2->get_next_op());
}


TEST_F(Lab01Fixture, isNext) {
    EXPECT_FALSE(stream1->end_is_next());


}
//todo: create a new test
//step 1: press alt+insert (or right click and select generate)
//step 2: choose test to generate a new test where the cursor is
//step 3: type "Lab01_Fixture" in the red box and press tab to go to next auto fill box
//step 4: type name of your test
//step 5: inside the function create your test, use previous test as examples
