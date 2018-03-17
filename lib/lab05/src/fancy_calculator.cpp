#include "fancy_calculator.h"
#include "stack.h"
#include "queue.h"
#include <string>
#include <map>
#include <iostream>
#include <sstream>

namespace lab5{
    std::map <char, int> operators;
    int eval(std::string op, int a, int b);
    bool is_operator(std::string input_string);
    int operator_priority(std::string operator_in) {
        int temp;
        if (operator_in == "*" || operator_in == "/")
            temp = 3;
        else  if (operator_in == "+" || operator_in == "-")
            temp = 2;
        return temp;
    }
    void calculator::parse_to_infix(std::string &input_expression) {
        std::stringstream ss;
        std::string temp;
        std::string str = "";
        ss.str(input_expression);
        while (ss >> temp)
        {
            infix_expression.enqueue(temp);
        }
        convert_to_postfix(infix_expression);
    }

    void calculator::convert_to_postfix(lab5::queue infix_expression) {
        lab5::stack stack;
        lab5::queue infix_copy(infix_expression);
        while(!infix_copy.isEmpty()) {
            std::string temp = infix_copy.top();
            if(is_number(temp)) {
                postfix_expression.enqueue(temp);
            }
            if(is_operator(temp)) {
                while( !stack.isEmpty() && ( ( (operator_priority(stack.top()) > operator_priority(temp)) ) || (operator_priority(stack.top()) == operator_priority(temp)) ) && (stack.top() != "(") )
                {
                    postfix_expression.enqueue(stack.top());
                    stack.pop();
                }
                stack.push(temp);
            }
            if(infix_copy.top() == "(") {
                stack.push(infix_copy.top());
            }
            if(infix_copy.top() == ")") {
                try {
                    while(stack.top() != "(") {
                        postfix_expression.enqueue(stack.top());
                        stack.pop();
                    }
                    stack.pop();
                }
                catch(...) {
                    throw std::invalid_argument("mismatched parenthesis");
                }
            }
            infix_copy.dequeue();
        }
        while(!stack.isEmpty()) {
            postfix_expression.enqueue(stack.top());
            stack.pop();
        }

    }
    void calculator::call_infix(std::string &input_expression) {
        parse_to_infix(input_expression);
    }

    calculator::calculator() {
        operators['*'] = 3;
        operators['/'] = 3;
        operators['+'] = 2;
        operators['-'] = 2;
    }

    calculator::calculator(std::string &input_expression) {
        lab1::expressionstream stream(input_expression);
        operators['*'] = 3;
        operators['/'] = 3;
        operators['+'] = 2;
        operators['-'] = 2;
        parse_to_infix(input_expression);
        convert_to_postfix(infix_expression);
    }

    std::istream &operator>>(std::istream &stream, calculator &RHS) {
        std::string temp;
        std::string expression;
        while(stream >> temp) {
            RHS.infix_expression.enqueue(temp);
        }
        RHS.convert_to_postfix(RHS.infix_expression);
        return stream;
    }

    int calculator::calculate() {
        lab5::stack digits;
        lab5::queue copy_postfix = postfix_expression;
        while(!copy_postfix.isEmpty()) {
            std::string temp = copy_postfix.top();
            copy_postfix.dequeue();
            if(is_operator(temp)) {
                std::string num1 = digits.top();
                digits.pop();
                std::string num2 = digits.top();
                digits.pop();
                int result = eval(temp, std::stoi(num1), std::stoi(num2));
                digits.push(std::to_string(result));
            }
            else if(is_number(temp)) {
                digits.push(temp);
            }
        }
        return std::stoi(digits.top());
    }

    std::ostream &operator<<(std::ostream &stream, calculator &RHS) {
        lab5::queue copy_postfix(RHS.postfix_expression);
        lab5::queue copy_infix(RHS.infix_expression);
        stream << "Infix: ";
        while(!copy_infix.isEmpty()) {
            stream << copy_infix.top() << (copy_infix.queueSize() == 1 ? "\n" : ",");
            copy_infix.dequeue();
        }
        stream << "Postfix: ";
        while(!copy_postfix.isEmpty()) {
            stream << copy_postfix.top() << (copy_postfix.queueSize() == 1 ? "" : ",");
            copy_postfix.dequeue();
        }
        return stream;
    }


    // AUXILIARY FUNCTIONS
    bool calculator::is_number(std::string input_string) {
        if (input_string.find('0') != std::string::npos ||
            input_string.find('1') != std::string::npos ||
            input_string.find('2') != std::string::npos ||
            input_string.find('3') != std::string::npos ||
            input_string.find('4') != std::string::npos ||
            input_string.find('5') != std::string::npos ||
            input_string.find('6') != std::string::npos ||
            input_string.find('7') != std::string::npos ||
            input_string.find('8') != std::string::npos ||
            input_string.find('9') != std::string::npos ||
            (input_string.find('-') != std::string::npos && input_string.length() > 1))
        {
            return true;
        }
        return false;
    }
    bool is_integer(char c) {
        return std::isdigit(c);
    }
    bool is_operator(std::string input_string) {
        if(input_string.length() > 1)
            return false;
        return operators.count(input_string[0]);
    }
    int eval(std::string op, int b, int a) {
        switch(op[0]) {
            case '*':
                return a * b;
            case '/':
                return a / b;
            case '+':
                return a + b;
            case '-':
                return a - b;
        }
    }

}

