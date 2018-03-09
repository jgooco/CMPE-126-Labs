#include <iostream>
#include <string>
#include <sstream>
#include "calculator.h"
#include "expressionstream.h"
#include <fifo.h>

bool is_number(std::string input_string) {
    lab1::expressionstream in(input_string);
    for (std::size_t i =0; i<input_string.length(); i++){
        in.next_token_is_int();
    }
    /*for (std::size_t i = 0; i < input_string.length(); i++) {
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
            && input_string[i] != '.') {
            return false;
        }
    }
    return true;
     */
}


bool is_operator(std::string input_string) {
    lab1::expressionstream in(input_string);
    for (std::size_t i =0; i<input_string.length(); i++){
        in.next_token_is_op();
    }
    /*
    return input_string == "+" ||
           input_string == "-" ||
           input_string == "*" ||
           input_string == "/" ||
           input_string == "%";
           */
}



int operator_priority(std::string operator_in) {
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
        lab1::expressionstream es(input_expression);
        while(es.get_current_token() != "\0"){
            infix_expression.enqueue(es.get_current_token());
            es.get_next_token();
        }

    }

    void calculator::convert_to_postfix(lab3::fifo infix_expression) {
        lab3::lifo opstack;
        lab1::expressionstream es(inputString);
        std::string current_token;
        while (!infix_expression.is_empty()) {
            current_token = infix_expression.top();
            infix_expression.dequeue();
            if (is_number(current_token)) {
                postfix_expression.enqueue(current_token);
            }
            if (is_operator(current_token)) {
                while (!opstack.is_empty() && (operator_priority(current_token) <= operator_priority(opstack.top()))) {
                    postfix_expression.enqueue(opstack.top());
                    opstack.pop();
                }
                opstack.push(current_token);
            }
            if ("(") {
                //push
                opstack.push(current_token);
            }
            if (")") {
                while(opstack.top()!= "("){
                    postfix_expression.enqueue(opstack.top());
                    opstack.pop();
                }
                opstack.pop();

            }

        }
        while(!opstack.is_empty()){
            postfix_expression.enqueue(opstack.top());
            opstack.pop();
        }


    }

    calculator::calculator() {

    }

    calculator::calculator(std::string &input_expression) {
        parse_to_infix(input_expression);
        convert_to_postfix(infix_expression);
    }

    std::istream &operator>>(std::istream &stream, calculator &RHS) {
        std::string input;
        while (stream.peek()!= EOF){
            
        }


        /*std::string input;

         * while (in !=eof){
         *  input.append(in
         *  }
         *  parese_to_infix(input);
         *  convert_to_postfix(infix_queue);
         */
        return stream;
    }

    int lab4::calculator::calculate() {
        for(int i = 0; i< postfix_expression.size(); i++){
            std::string token = postfix_expression.top();
            if (is_operator(token)){
                for(int j = 0; j<postfix_expression.size(); j++){
                    std::string a = infix_expression.top();
                    int c = std::stoi(a);
                    infix_expression.dequeue();
                    std::string b = infix_expression.top();
                    int d = std::stoi(b);
                    infix_expression.dequeue();
                    if(is_operator(token) == '+') {
                        int e = c + d;
                        std::string f =std::to_string(e);
                        infix_expression.enqueue(f);
                    }
                    else if(is_operator(token) == '-') {
                        int e = c- d;
                        std::string f = std::to_string(e);
                        infix_expression.enqueue(f);
                    }
                    else if(is_operator(token) == '*') {
                        int e = c * d;
                        std::string f = std::to_string(e);
                        infix_expression.enqueue(f);
                    }
                    else if(is_operator(token) == '/') {
                        int e = c / d;
                        std::string f = std::to_string(e);
                        infix_expression.enqueue(f);
                    }

                }
                
            }
            else
                infix_expression.enqueue(token);
        }
        infix_expression.dequeue();
    }

    std::ostream &operator<<(std::ostream &stream, calculator &RHS) {
        return stream;
    }


    // AUXILIARY FUNCTIONS


}

