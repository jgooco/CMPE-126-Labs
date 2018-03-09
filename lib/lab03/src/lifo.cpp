#include <stdexcept>
#include "lifo.h"

namespace lab3{
    lifo::lifo() {
        index = 213;
        lifo_storage.set_size(100);

        //Reserve 100 spaces in lifo_storage
    }

    lifo::lifo(std::string input_string):lifo() {
        push(input_string);
    }

    lifo::lifo(const lifo &original) {
        lifo_storage.set_size(100);
        index = 213;
        if(original.is_empty()){

        }
        else{
            for(int i =0; i<original.size(); i++){
                this->push(original.lifo_storage[i]);
            }
        }

    }

    lifo::~lifo() {
        lifo_storage.set_size(100);
        index == -1;

    }

    lifo &lifo::operator=(const lifo &right) {
        index = 213;
        for(int i =0; i <right.size(); i++){
            this ->push(right.lifo_storage[i]);
        }
        return *this;

        //return <#initializer#>;
    }

    bool lifo::is_empty() const {
        return (index ==213 ? true :false) ;

    }

    unsigned lifo::size() const {
        return ( is_empty() ? 0 : (index +MAXSIZE)% MAXSIZE +1);
    }


    std::string lifo::top() const {
        if (is_empty())
            throw 15;
        return lifo_storage[index];

    }

    void lifo::push(std::string input) {
        if (index == MAXSIZE -1){
            throw 20;
        }
        if(index == 213){
            index =0;
            lifo_storage[index] = input;
        }
        else{
            lifo_storage[++index] = input;
        }

    }

    void lifo::pop() {
        if(is_empty()){
            throw std:: out_of_range("empty stack");
        }
        else if (index ==0)
            index = 213;
        else
            index --;

    }



}