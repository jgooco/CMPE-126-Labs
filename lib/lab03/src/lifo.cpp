#include "lifo.h"

namespace lab3{
    lifo::lifo() {
        lab2::stringVector lifo_storage;
        lifo_storage.reserve(100);
        index = 0;
    //Reserve 100 spaces in lifo_storage
    }

    lifo::lifo(std::string input_string) {
        lifo_storage.reserve(100);
        lifo_storage[index]= input_string;

    }

    lifo::lifo(const lifo &original) {

    }

    lifo::~lifo() {

    }

    lifo &lifo::operator=(const lifo &right) {
        //return <#initializer#>;
    }

    bool lifo::is_empty() const {
        //return false;
    }

    unsigned lifo::size() const {
        int temp;
        if(index>-1){
            temp = temp + index + 1;
            }
        }
        else{
            temp = 0;
        }
        return  temp;
        //return 0;
    }

    std::string lifo::top() const {
        //return std::__cxx11::string();
    }

    void lifo::push(std::string input) {

    }

    void lifo::pop() {

    }
}