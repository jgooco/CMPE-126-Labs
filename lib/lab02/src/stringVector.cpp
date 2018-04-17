#include <iostream>
#include "../inc/stringVector.h"

namespace lab2 {
    stringVector::stringVector() {
        data = nullptr;
        length = 0;
        allocated_length = 0;

    }

    stringVector::~stringVector() {
        delete[]data;
    }

    unsigned stringVector::size() const {
        return length;
        //return ;
    }

    unsigned stringVector::capacity() const {
        return allocated_length;
        //return ;
    }

    void stringVector::reserve(unsigned new_size) {
        std::string *temp = new std::string[new_size];
        if (new_size< length){
            length =new_size;
        }
        for (int i=0; i<length; i++){
            temp[i] = data[i];
        }
        delete[] this -> data;
        data = temp;
        allocated_length = new_size;


    }

    bool stringVector::empty() const {
        return length == 0;
    }

    void stringVector::append(std::string new_data) {
        std::string *temp = nullptr;
        if (length == allocated_length) {
            if (allocated_length == 0) {
                data = new std::string[1];
                allocated_length = 1;
            } else {
                temp = new std::string[2 * allocated_length];
                for (int i = 0; i < length; i++) {
                    temp[i] = data[i];
                }
                allocated_length = 2 * allocated_length;
                if (data != nullptr)
                    delete[]data;
                data = temp;
            }
        }
        data[length] = new_data;
        length++;
    }

    void stringVector::swap(unsigned pos1, unsigned pos2) {
        std::string str;
        if ((pos1 >= allocated_length) || (pos2 >= allocated_length)) {
            std::cout << "Index Out of bounds" << std::endl;
            throw 42;
        }

        str = data[pos1];
        data[pos1] = data[pos2];
        data[pos2] = str;
    }

    stringVector &stringVector::operator=(stringVector const &rhs) {
        if(this!=&rhs) {
            length = rhs.length;
            allocated_length = rhs.allocated_length;

            if (data != NULL)
                delete[] data;

            data = new std::string[allocated_length];

            for (int i = 0; i < length; i++)
                this->data[i] = rhs.data[i];
        }
        return *this;
    }

    std::string &stringVector::operator[](unsigned position) const {
        if (position >= length) {
            throw 'out of range';
        }

        return data[position];
    }

    void lab2::stringVector::set_size(unsigned new_size) {
        //length = new_size;
        if(allocated_length != new_size)
            reserve(new_size);
        length = new_size;
    }

    void stringVector::sort() {
        std::string str;

        for (int i = (length - 1); i > 0; i--) {

            for (int j = 0; j < i; j++) {
                if (data[j].compare(data[j + 1]) > 0) {
//Swap
                    str = data[j];
                    data[j] = data[j + 1];
                    data[j + 1] = str;
                }
            }
        }
    }


}