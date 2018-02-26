#include <iostream>
#include <string>
#include <sstream>
#include "calculator.h"
#include <fifo.h>
bool is_number(std::string input_string){
    for(std::size_t i =0; i < input_string.length(); i++){
        if (input_string[i] != '0'
            && input_string[i] != '1'
            && input_string[i] != '2'
            && input_string[i] != '3'
            && input_string[i] != '4'
            && input_string[i] != '5'
            && input_string[i] != '6'
            && input_string[i] != '7'
            && input_string[i] != '8'
            && input_string[i] != '9'
            && input_string[i] != '.'){
            return false;
        }
    }
    return true;
}


bool is_operator(std::string input_string){
    return input_string == "+" ||
           input_string == "-" ||
           input_string == "*" ||
           input_string == "/" ||
           input_string == "%"
}

int get_number(std::string input_string);

std::string get_operator(std::string input_string);

int operator_priority(std::string operator_in){
    if (operator_in == "^")
        return 3;
    if (operator_in == "*" || operator_in == "/")
        return 2;
    if (operator_in == "+" || operator_in == "-")
        return 1;
    else
        return 0;
}
namespace lab4 {
    void calculator::parse_to_infix(std::string &input_expression) {
        std::string::iterator position = input_expression.begin();
        std::string::iterator end = input_expression.end();
        for (position; position != end && *position == ' '; position ++)
        {
            is_number(*position);
        }

    }

    void calculator::convert_to_postfix(lab3::fifo infix_expression) {
        parse_to_infix(inputString);
        std::istringstream iss(inputString);
        lab2::stringVector tokens;
        while(iss){
            std::string temp;
            iss >> temp;
            infix_expression.enqueue(temp);
        }
        lab2::stringVector output;
        lab3::lifo s;

        for(unsigned int i = 0; i<tokens.size(); i++){
            if(TryParse(tokens[i]))
                output.
        }


    }

    calculator::calculator() {

    }

    calculator::calculator(std::string &input_expression) {
        parse_to_infix(input_expression);
        convert_to_postfix(infix_expression);
    }

    std::istream &operator>>(std::istream &stream, calculator &RHS) {
        return stream;
    }

    int lab4::calculator::calculate() {
        return 0;
    }

    std::ostream &operator<<(std::ostream &stream, calculator &RHS) {
        return stream;
    }


    // AUXILIARY FUNCTIONS

}

