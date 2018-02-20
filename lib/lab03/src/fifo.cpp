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
        fifo_storage.reserve(100);
        front_index = 123;
        back_index = 123;
        enqueue(input_string);

    }

    fifo::fifo(const fifo &original) {
        fifo_storage.reserve(100);
        front_index = original.front_index;
        back_index = original.back_index;
        if(original.is_empty()){

        }
        else{
            int s = (back_index + MAXSIZE - front_index) % MAXSIZE +1;
            for(int i=0; i<s; i++){
                int current = (front_index+1) %MAXSIZE;
                fifo_storage[current] = original.fifo_storage[current];
            }
        }


    }

    fifo::~fifo() {
        fifo_storage.set_size(100);
        front_index == -1;
        back_index == -1;

    }

    fifo &fifo::operator=(const fifo &right) {
        //return <#initializer#>;
        front_index = right.front_index;
        back_index = right.back_index;
        if (right.is_empty()){

        }
        else{
            int s= (back_index + MAXSIZE - front_index) & MAXSIZE +1;
            for(int i =0; i<s; i++){
                int current = (front_index +1) %MAXSIZE;
                fifo_storage[current]= right.fifo_storage[current];
            }
        }
        return *this;
    }

    bool fifo::is_empty() const {
       return (front_index == 123 && back_index == 123);


        //return false;
    }

    unsigned fifo::size() const {
        if (is_empty())
            return 0;
        return (back_index - front_index)%MAXSIZE+1;


        //return 0;
    }

    bool fifo::is_full() const{
        return ((back_index +1)% MAXSIZE == front_index ? true: false);

}

    std::string fifo::top(){
        return  fifo_storage[front_index];

        //return std::__cxx11::string();
    }

    void fifo::enqueue(std::string input) {
        if(is_full()){
            throw 30;
        }
        if(is_empty()){
            front_index = back_index = 0;
        }
        else
            back_index = (back_index +1) %MAXSIZE;
        fifo_storage[back_index] = input;
    }

    void fifo::dequeue() {
        if(is_empty()){
            throw 1;
        }
        else if(front_index == back_index){
            back_index= front_index = 123;

        }
        else {
            front_index = (front_index+1)%MAXSIZE;
        }

    }
}