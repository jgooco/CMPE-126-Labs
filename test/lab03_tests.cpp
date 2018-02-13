#include "gtest/gtest.h"
#include "fifo.h"
#include "lifo.h"


namespace lab3 {

    TEST(fifo, constructorTest) {
        fifo constructor;
        EXPECT_TRUE(constructor.is_empty());

    }


}