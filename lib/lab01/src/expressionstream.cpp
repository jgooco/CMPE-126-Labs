#include "expressionstream.h"

bool is_operator(char c);
bool is_digit(char c);

/*Basic constructor: puts input string into buffer and points all string iterators to beginning of buffer*/
expressionstream::expressionstream(const std::string &string_in) : buffer(string_in) {
    pos_next = buffer.begin();
    pos_next_int= buffer.begin();
    pos_next_op = buffer.begin();
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

    while(pos_next_int != buffer.end() && is_operator(*pos_next_int)){ //align next_int with next digit in buffer
        if(*pos_next_int!=' ') {// spaces are ignored
            if (op_found) {
                if (*pos_next_int == '-') {
                    is_neg = true;
                }
            } else {
                op_found = true;
            }
        }
        pos_next_int++;
    }
    int_end = pos_next_int +1;

    while(int_end != buffer.end() && is_digit(*int_end)) int_end++;

    integer = std::string(pos_next_int,int_end);
    pos_next_int=int_end;

    if(is_neg) integer = '-' + integer;
    align_next_int();
    update_pos_next();
    return integer;
}

//todo: update get_next operators to handle negative first numbers
std::string expressionstream::get_next_op() {
    while(pos_next_op != buffer.end() && !is_operator(*pos_next_op))pos_next_op++;
    std::string::iterator op_start=pos_next_op++;
    update_pos_next();
    return std::string(op_start,pos_next_op);
}

void expressionstream::update_pos_next() {
    if (pos_next_op > pos_next_int)
        pos_next = pos_next_int;
    else
        pos_next = pos_next_op;
}

void expressionstream::find_next_int() {
    bool is_neg=false, op_found=false; //is_neg == negative number found, op_found == operator already found(helps with negative numbers)
    std::string::iterator int_end;//next_int will point to the beginning of a number, int_end will point to the end

//    while(pos_next_int != buffer.end() && is_operator(*pos_next_int)){ //align next_int with next digit in buffer
//        if(*pos_next_int!=' ') {// spaces are ignored
//            if (op_found) {
//                if (*pos_next_int == '-') {
//                    is_neg = true;
//                }
//            } else {
//                op_found = true;
//            }
//        }
//        pos_next_int++;
//    }

    if(*pos_next_int == '-') {
        is_neg=true;
        pos_next_int++;
    }
    int_end = pos_next_int +1;
    while(int_end != buffer.end() && is_digit(*int_end)) int_end++;

    next_int = std::string(pos_next_int,int_end);
    pos_next_int=int_end;

    if(is_neg) next_int = '-' + next_int;
}

void expressionstream::find_next_op() {

}

void expressionstream::align_next_int() {
    bool op_found=false; //is_neg == negative number found, op_found == operator already found(helps with negative numbers)
    while (pos_next_int != buffer.end() && !is_digit(*pos_next_int) || (op_found && *pos_next_int !='-')){//not end of file && not a digit(beginning of a number) && not a negative number beginning
        if(is_operator(*pos_next_int))op_found= true;
        pos_next_int++;
    }
}

void expressionstream::align_next_op() {

}

bool is_digit(char c){
    return (c >= '0' && c <= '9');
}

bool is_operator(char c){
    return (c=='+' || c=='-' || c=='*' || c=='/' || c=='(' || c==')' || c=='^');
}

