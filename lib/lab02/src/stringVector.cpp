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

void stringVector::reserve(unsigned new_size) {
    if (new_size == 0){
        length = 0;
        allocated_length = 0;
        delete [] this->data;
        this->data = nullptr;
        return;
    }
    else if (new_size == allocated_length){
        //If the user wants the new size to be size it already is, nothing needs to be done
        return;
    }
    else{
        auto * temp = new std::string[new_size];
        if (new_size < length){length = new_size;}
        //If new size is less than the original, the original data will need to be truncated
        for (int i=0;i<length;i++){
            temp[i] = data[i];
            //Copy old data to new array
        }
        delete [] this->data;
        data = temp;
        //Delete old array and point the data pointer to the newly allocated array
        allocated_length = new_size;
    }
}

bool stringVector::empty() const {
    return length == 0;
}

void stringVector::append(std::string new_data) {
    if (allocated_length > length){

        data[length] = new_data;
        length++;
        return;
    }
    else{
        this->reserve(allocated_length>0?allocated_length*2:1);
        this->append(new_data);
    }
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