#include <iostream>
#include "../inc/stringVector.h"

stringVector::stringVector() {
    data = nullptr;
    length = 0;
    allocated_length =0;

}

stringVector::~stringVector() {
    delete []data;
}

unsigned stringVector::size() const{
    return length;
    //return ;
}

unsigned stringVector::capacity() const{
    return allocated_length;
    //return ;
}

void stringVector::reserve(unsigned new_size)
{
    std::string *temp = new std::string[new_size]; // Create a new array

/*Copy the contents of the array*/
    for(int i =0; i < new_size; i++){
        if(i < length){
            temp[i] = data[i];
        }
        else
            break;
    }

    delete []data ;// Delete previous array
    data = temp;

    allocated_length = new_size;

    if(length > new_size){
        length = new_size;
    }
}

bool stringVector::empty() const {
    return length == 0;
}

void stringVector::append(std::string new_data)
{
    std::string *temp = nullptr;

    if(length == allocated_length){

        if(allocated_length == 0){
            data = new std::string[10];
            allocated_length = 10;
        }
        else{
            temp = new std::string[2 * allocated_length]; // Create a new array with double the size
            for(int i = 0; i < length ; i++){
                temp[i] = data[i];
            }
            allocated_length = 2 * allocated_length;

            if(data != nullptr)
                delete []data;
            data = temp;
        }
    }

    data[length] = new_data;
    length++;
}

void stringVector::swap(unsigned pos1, unsigned pos2)
{
    std::string str;
    if((pos1 >= length) || (pos2 >= length)){
        std::cout << "Index Out of bounds" << std::endl;
        return;
    }

    str = data[pos1];
    data[pos1] = data[pos2];
    data[pos2] = str;
}

stringVector& stringVector::operator = (stringVector const &rhs)
{
    delete [] data;
    length = rhs.length;
    allocated_length = rhs.allocated_length;

    this->data = new std::string[allocated_length];

    for(int i=0 ; i < length; i++)
        this->data[i] = rhs.data[i];
}

std::string& stringVector::operator[](unsigned position)
{
    if(position > length){
        throw std::out_of_range("Position out of range");
    }

    return data[position - 1];
}


void stringVector::sort()
{
    std::string str;

    for(int i= (length - 1) ; i > 0; i--){

        for(int j = 0; j < i; j++){
            if(data[j].compare(data[j+1]) > 0){
//Swap
                str = data[j];
                data[j] = data[j+1];
                data[j+1] = str;
            }
        }
    }
}