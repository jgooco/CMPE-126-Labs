#include "queue.h"
#include "linked_list.h"
#include "node.h"
namespace lab5{
    queue::queue() {

    }

    queue::queue(std::string &data) {
        enqueue(data);
    }

    queue::queue(const queue &original) {
        (*this) = original;
    }

    queue::~queue() {

    }

    queue &queue::operator=(const queue &RHS) {
        storage_structure = RHS.storage_structure;
        if(RHS.isEmpty()){
            throw 51;
        }
        else{

        }
        return *this;
        //return <#initializer#>;
    }

    bool queue::isEmpty() const {
        return storage_structure.isEmpty();
    }

    unsigned queue::queueSize() const {
        return storage_structure.listSize();
    }

    std::string queue::top() const {
        return storage_structure.get_value_at(0);
        //return std::__cxx11::string();
    }

    void queue::enqueue(const std::string &data) {
        storage_structure.append(data);
    }

    void queue::dequeue() {
        storage_structure.remove(1);
    }

    std::ostream& operator<<(std::ostream &stream, queue &RHS) {
        lab5::linked_list storage;
        stream << storage;
        return stream;
    }

    std::istream& operator>>(std::istream &stream, queue &RHS) {
        lab5::linked_list storage;
        stream >> storage;
        return stream;
    }
}