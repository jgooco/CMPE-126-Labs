#include <iostream>
#include "stringVector.h"

int main() {
    stringVector sample;
    sample.append(std::string("example 1"));
    std::cout << sample[0] << std::endl;
    return 0;
}