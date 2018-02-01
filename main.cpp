#include <iostream>

int main() {
    // Print "Woof" when I is divisible by  7
    for(int i =1; i<=100; i++)
    {
        if(i%3 == 0) std::cout << "Fizz" << std::endl;
        if(i%5 == 0) std::cout << "Buzz" << std::endl;

    }
    return 0;
}