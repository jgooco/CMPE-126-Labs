#include "fifo.h"
#include "stringVector.h"

namespace lab3{
    fifo::fifo() {
        fifo_storage.reserve(100);
        front_index = 123;
        back_index = 123;
    //Reserve 100 spaces in fifo_storage
    }

    fifo::fifo(std::string input_string) {
        fifo_storage.set_size(100);
        fifo_storage[back_index]= input_string;

    }

    fifo::fifo(const fifo &original) {


    }

    fifo::~fifo() {
        fifo_storage.set_size(100);
        front_index == -1;
        back_index == -1;

    }

    fifo &fifo::operator=(const fifo &right) {
        //return <#initializer#>;
        if (&right == this){
            return *this;
        }
        else
        {
            fifo_storage = right.fifo_storage;
            front_index = right.front_index;
            back_index = right.back_index;
        }
        return (*this);
    }

    bool fifo::is_empty() const {
       return (front_index == 123 && back_index == 123);


        //return false;
    }

    unsigned fifo::size() const {
        if (is_empty())
            return 0;
        return (back_index + MAXSIZE - front_index) % MAXSIZE +1;


        //return 0;
    }

    std::string fifo::top(){
        if(front_index == -1 ){
            throw 69;
        }
        return fifo_storage[front_index];

        //return std::__cxx11::string();
    }

    void fifo::enqueue(std::string input) {
        if((back_index +1) % MAXSIZE == front_index)
            throw 69;
        if (is_empty()){
            front_index = back_index =0;
        }
        else{
            back_index = (back_index +1)%MAXSIZE;

        }
        fifo_storage[back_index] = input;
    }

    void fifo::dequeue() {
        if(is_empty()){
            throw 1;
        }
        else if(front_index == back_index){
            front_index = 123;
            back_index = 123;

        }
        else {
            front_index = (front_index+1)%MAXSIZE;
        }

    }
}