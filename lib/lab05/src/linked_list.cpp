#include <linked_list.h>
namespace lab5 {
    linked_list::linked_list() {
        head = nullptr;
        tail = nullptr;

    }

    linked_list::linked_list(std::string &data) {


    }

    linked_list::linked_list(const linked_list &original) {
        (*this) = original;

    }

    linked_list::~linked_list() {
        delete[] head;
        delete[] tail;

    }

    linked_list &lab5::linked_list::operator=(const linked_list &RHS) {
        //return <#initializer#>;
    }


    bool linked_list::isEmpty() const {
        return false;
    }

    unsigned linked_list::listSize() const {
        return 0;
    }

    void linked_list::insert(const std::string input, unsigned int location) {
        node *temp = new node(input);
        temp->data = input;
        temp->next = nullptr;





    }

    void linked_list::append(const std::string input) {
        node *temp = new node(input);
        temp->data = input;
        temp->next = nullptr;
        if(head==nullptr){
            head = temp;
            return;
        }
        while(tail->next != nullptr){
            tail = tail->next;
            tail->next = temp;
            return;
        }



    }

    void linked_list::remove(unsigned location) {
        node *curr;
        node *prev;
        curr = head;
        for(int i =1; i<location; i++){
                prev= curr;
            curr = curr->next;
        }
        prev->next=curr->next;

    }

    std::ostream& operator<<(std::ostream &stream, linked_list &RHS) {
        return stream;
    }

    std::istream& operator>>(std::istream &stream, linked_list &RHS) {
        return stream;
    }

    void linked_list::sort() {


    }
}