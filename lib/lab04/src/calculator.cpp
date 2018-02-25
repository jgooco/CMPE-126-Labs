#include <iostream>
#include <string>
#include <sstream>
#include "calculator.h"
#include <fifo.h>
namespace lab4 {
    void calculator::parse_to_infix(std::string &input_expression) {
        std::stringstream ss(input_expression);

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
    //bool is_number(std::string input_string);
    bool TryParse(const std::string &symbol)
    {
        bool isNumber = false;
        for(unsigned int i = 0; i < symbol.size(); i++)
        {
            if(!isdigit(symbol[i]))
            {
                isNumber = false;
            }
            else
            {
                isNumber = true;
            }
        }
        return isNumber;
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
}

