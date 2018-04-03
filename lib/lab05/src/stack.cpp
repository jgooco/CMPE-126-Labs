#include "stack.h"
namespace lab5{
    stack::stack() {

    }

    stack::stack(std::string &data) {
        push(data);
    }

    stack::stack(const stack &original) {
        (*this) = original;
    }

    stack::~stack() {

    }

    stack &stack::operator=(const stack &RHS) {
        storage_structure = linked_list(RHS.storage_structure);

        //return <#initializer#>;
    }

    bool stack::isEmpty() const {
        return storage_structure.isEmpty();
    }

    unsigned stack::stackSize() const {
        return storage_structure.listSize();
    }

    std::string stack::top() const {
        return storage_structure.get_value_at(0);
        //return std::__cxx11::string();
    }

    void stack::push(const std::string &data) {
        storage_structure.insert(data, 0);

    }

    void stack::pop() {
        storage_structure.remove(0);

    }

    std::ostream& operator<<(std::ostream &stream, stack &RHS) {

        return stream;
    }

    std::istream& operator>>(std::istream &stream, stack &RHS) {
        return stream;
    }
}