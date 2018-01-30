#include "expressionstream.h"

bool is_operator(char c);
bool is_digit(char c);

/*Basic constructor: puts input string into buffer and points all string iterators to beginning of buffer*/
expressionstream::expressionstream(const std::string &string_in) : buffer(string_in) {
    pos_next = buffer.begin();
    next_int= buffer.begin();
    next_op = buffer.begin();
}

/*returns current buffer as a string. This will return the entire expression.*/
std::string expressionstream::str() const {
    return buffer;
}

/*Used to replace the buffer with a new expression*/
void expressionstream::str(const std::string &s) {
    buffer = s;
}

/*checks to see if the iterator that is furthest behind has reached the end.
 * This will show that all of the string has been analyzed.*/
bool expressionstream::end_is_next() {
    return pos_next == buffer.end();
}

/*will return each integer as a string one by one, in order. E.G. "1+2+3" a call to get next int would return a 1, another
 * call would return a 2, the next call would return a 3. All subsequent calls would return EOF*/
std::string expressionstream::get_next_int() {
    bool is_neg=false, op_found=false; //is_neg == negative number found, op_found == operator already found(helps with negative numbers)
    std::string::iterator int_end;//next_int will point to the beginning of a number, int_end will point to the end
    std::string integer;//once the beginning and the end of the number have been found the string is created and stored in integer

    while(next_int != buffer.end() && is_operator(*next_int)){ //align next_int with next digit in buffer
        if(*next_int!=' ') {// spaces are ignored
            if (op_found) {
                if (*next_int == '-') {
                    is_neg = true;
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

