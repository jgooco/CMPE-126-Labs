#include "gtest/gtest.h"
#include "linked_list.h"
#include "queue.h"
#include "stack.h"
#include "fancy_calculator.h"

namespace lab5 {
    TEST(linkedlist, constructor_test){
        lab5::linked_list test;
        EXPECT_EQ(0,test.listSize());
        EXPECT_TRUE(test.isEmpty());
    }
    TEST(linkedlist, inserttest){
        lab5::linked_list test1;
        test1.insert("1", 1);
        test1.insert("9", 2);
        EXPECT_EQ(2, test1.listSize());
        EXPECT_EQ("1", test1.get_value_at(0));
        EXPECT_EQ("9", test1.get_value_at(1));
    }
    TEST(linkedlist, appendtest){
        lab5::linked_list test2;
        test2.append("42");
        test2.append("101");
        test2.append("One");
        EXPECT_EQ(3, test2.listSize());
        EXPECT_EQ("42", test2.get_value_at(0));

    }

    TEST(linkedlist, insertandappend){
        lab5::linked_list test3;
        test3.insert("2", 1);
        test3.insert("4", 2);
        test3.append("hello world!");
        EXPECT_EQ(3, test3.listSize());
    }


}
