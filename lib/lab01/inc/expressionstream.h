#ifndef CMPE126S18_LABS_STSTRING_H
#define CMPE126S18_LABS_STSTRING_H


#include <string>

class expressionstream {
private:
    std::string buffer;
    std::string::iterator pos_next;
    std::string::iterator next_int;
    std::string::iterator next_op;

    void update_pos_next();

public:
    explicit expressionstream(const std::string &string_in);

    std::string str() const;
    void str (const std::string& s);

    bool integer_is_next();
    bool operator_is_next();
    bool end_is_next();

    std::string get_next_int();
    std::string get_next_op();

};


#endif //CMPE126S18_LABS_STSTRING_H
