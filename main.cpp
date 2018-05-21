#include <iostream>
int func(int x);
int main() {


    std::cout <<func(2) << std:: endl;
    std::cout <<func(3) << std:: endl;
    std::cout <<func(4) << std:: endl;
    std::cout <<func(5) << std:: endl;
}

int func(int x){
    if(!x) return 1;
    else if (!(x-1)) return 2;
    else return func(x-1) + func(x-2);

}