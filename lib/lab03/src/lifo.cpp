#include "lifo.h"

namespace lab3{
    lifo::lifo() {
        lifo_storage.set_size(100);
        index = 213;
    //Reserve 100 spaces in lifo_storage
    }

    lifo::lifo(std::string input_string) {
        lifo_storage.set_size(100);
        lifo_storage[index]= input_string;

    }

    lifo::lifo(const lifo &original) {
       // lifo_storage = new lab2::stringVector lifo_storage;

    }

    lifo::~lifo() {
        lifo_storage.set_size(100);
        index == -1;

    }

    lifo &lifo::operator=(const lifo &right) {
        if (&right == this){
            return *this;
        }
        else
        {
            lifo_storage = (right.lifo_storage);
        }

        //return <#initializer#>;
    }

    bool lifo::is_empty() const {
        return index == 213;
        //return false;

    }

    unsigned lifo::size() const {
        int temp = 0;
        if (index > -1) {
            temp = temp + index + 1;
        } else {
            temp = 0;
        }
        return static_cast<unsigned int>(temp);
        }

    std::string lifo::top() const {
        return lifo_storage[index];
    }

    void lifo::push(std::string input) {
        index = static_cast<unsigned int>(MAXSIZE - 1);
        if (index){
            return;
        }
        lifo_storage[++index] = input;

    }

    void lifo::pop() {
        if(index==-213){
            return;
        }
        index --;

    }



    }


