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
        this->storage_structure = original.storage_structure;
    }

    queue::~queue() {

    }

    queue &queue::operator=(const queue &RHS) {
        //return <#initializer#>;
    }

    bool queue::isEmpty() const {
        return storage_structure.isEmpty();
    }

    unsigned queue::queueSize() const {
        return storage_structure.listSize();
    }

    std::string queue::top() const {

        //return std::__cxx11::string();
    }

    void queue::enqueue(const std::string &data) {
        storage_structure.append(data);
    }

    void queue::dequeue() {
        storage_structure.remove(0);
    }

    std::ostream& operator<<(std::ostream &stream, queue &RHS) {
        return stream;
    }

    std::istream& operator>>(std::istream &stream, queue &RHS) {
        return stream;
    }
}