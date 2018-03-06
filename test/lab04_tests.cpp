#include "gtest/gtest.h"
#include "fifo.h"
#include "lifo.h"
#include "calculator.h"

namespace lab4 {
    TEST(calculator,additionTest) {
        std::string test1 = "9+10";
        lab4::calculator obj1(test1);
        EXPECT_EQ(10,obj1.calculate());
    }

    /*TEST(calculator,subtractionTest){
        lab4::calculator obj2("5-3-6");
        EXPECT_EQ(-4,obj2.calculate());
    }

    TEST(calculator,divisionTest){
        lab4::calculator obj3("100/20");
        EXPECT_EQ(5,obj3.calculate());

        //Allows for floating point calculations
        EXPECT_NO_THROW(obj3.setEQ("12.5/5"));
        EXPECT_EQ(2.5,obj3.calculate<double>());
    }

    TEST(calculator,multiplicationTest){
        lab4::calculator obj4("2*2*5");
        EXPECT_EQ(20,obj4.calculate());
    }

    TEST(calculator,parenthesisTest){
        lab4::calculator obj5("5*(10-4)");
        EXPECT_EQ(30,obj5.calculate());
    }

    TEST(calculator,lotsOfStuffTest){
        //This combines most of the other tests
        lab4::calculator obj6("((((5+6/3)*2)-(12--1*(15/3+7)))+2)*(1/4)");
        EXPECT_EQ(-2,obj6.calculate());
    }

    TEST(calculator,leadingMinusTest){
        //Testing to make sure code doesn't crash when given a leading -
        //Other operators aside from '(' are invalid if leading
        lab4::calculator obj7("-(10+20)");
        EXPECT_EQ(-30,obj7.calculate());
    }*/
}
