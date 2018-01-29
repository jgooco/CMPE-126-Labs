#include "expressionstream.h"

bool is_operator(char c);
bool is_digit(char c);

expressionstream::expressionstream(const std::string &string_in) : buffer(string_in) {
    pos_next = buffer.begin();
    next_int= buffer.begin();
    next_op = buffer.begin();
}

std::string expressionstream::str() const {
    return buffer;
}

void expressionstream::str(const std::string &s) {
    buffer = s;
}

bool expressionstream::end_is_next() {
    return pos_next == buffer.end();
}

std::string expressionstream::get_next_int() {
    bool is_neg=false, op_found=false;
    std::string::iterator int_end;
    std::string integer;

    while(next_int != buffer.end() && is_operator(*next_int)){ //align next_int with next digit in buffer
        if(*next_int!=' ') {
            if (op_found) {
                if (*next_int == '-') {
                    is_neg = true;
                } else {
                    throw "String contains errors";//could be more than one operator side by side
                }
            } else {
                op_found = true;
            }
        }
        next_int++;
    }
    int_end = next_int +1;

    while(int_end != buffer.end() && is_digit(*int_end)) int_end++;

    integer = std::string(next_int,int_end);
    next_int=int_end;

    if(is_neg) integer = '-' + integer;
    update_pos_next();
    return integer;
}

//todo: update get_next operators to handle negative first numbers
std::string expressionstream::get_next_op() {
    while(next_op != buffer.end() && !is_operator(*next_op))next_op++;
    std::string::iterator op_start=next_op++;
    update_pos_next();
    return std::string(op_start,next_op);
}

void expressionstream::update_pos_next() {
    if (next_op > next_int)
        pos_next = next_int;
    else
        pos_next = next_op;
}

bool is_digit(char c){
    return (c >= '0' && c <= '9');
}

bool is_operator(char c){
    return (c=='+' || c=='-' || c=='*' || c=='/' || c=='(' || c==')' || c=='^');
}

