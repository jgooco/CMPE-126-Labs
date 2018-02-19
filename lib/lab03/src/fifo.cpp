#include "fifo.h"
#include "stringVector.h"

namespace lab3{
    fifo::fifo() {
        lab2::stringVector fifo_storage;
        fifo_storage.set_size(100);
        front_index = 0;
        back_index = 0;
    //Reserve 100 spaces in fifo_storage
    }

    fifo::fifo(std::string input_string) {
        fifo_storage.reserve(100);
        fifo_storage[back_index]= input_string;

    }

    fifo::fifo(const fifo &original) {

    }

    fifo::~fifo() {
        fifo_storage.set_size(100);
        front_index = -1;
        back_index = -1;

    }

    fifo &fifo::operator=(const fifo &right) {
        //return <#initializer#>;
    }

    bool fifo::is_empty() const {
        //return false;
    }

    unsigned fifo::size() const {
        //return 0;
    }

    std::string fifo::top() const {
        //return std::__cxx11::string();
    }

    void fifo::enqueue(std::string input) {
        if (back_index == 1){
            back_index = 0;
            front_index = back_index;
        }

    }

    void fifo::dequeue() {

    }
}