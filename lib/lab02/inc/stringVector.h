
#ifndef CMPE126S18_LABS_STRINGVECTOR_H
#define CMPE126S18_LABS_STRINGVECTOR_H

#include <string>

class stringVector {
private:
    std::string * data;
    unsigned length;
    unsigned allocated_length;

public:
    stringVector();
    virtual ~stringVector();

    unsigned size();
    unsigned capacity();
    void resize();
    bool empty();
    void append(std::string data);
    stringVector &operator = (stringVector const &rhs);
    std::string& operator[](unsigned position);
};


#endif //CMPE126S18_LABS_STRINGVECTOR_H
