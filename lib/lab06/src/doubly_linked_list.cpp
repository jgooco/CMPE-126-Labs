#include "../inc/doubly_linked_list.h"

namespace lab6{
    doubly_linked_list::doubly_linked_list() {
        head = nullptr;
        tail = nullptr;

    }

    doubly_linked_list::doubly_linked_list(int input) {
        head = new node(input);
        tail = head;
        append(input);

    }

    doubly_linked_list::doubly_linked_list(std::vector<int> vector_input) {

    }

    doubly_linked_list::doubly_linked_list(const doubly_linked_list &original) {
        head = nullptr;
        tail = nullptr;
        node *temp = head;
        for(int i = 0; i<original.size(); i++){
            append(temp->get_data());
            temp = temp->next;
        }

    }

    doubly_linked_list::~doubly_linked_list() {
        node* current = head;
        node* next;
        while(current != nullptr){
            next = current->next;
            delete current;
            current = next;
        }
        head  = nullptr;

    }

    int doubly_linked_list::get_data(unsigned position) {
        node* current = head;
        unsigned int count = 0;
        while(current != nullptr){
            if(count == position)
                current->get_data();
            count++;
            current = current->next;
        }

    }

    std::vector<int> doubly_linked_list::get_set(unsigned position_from, unsigned position_to) {

    }

    unsigned doubly_linked_list::size()const {
        node* current = head;
        unsigned int count =0;
        while(current != nullptr){
            count ++;
            current = current->next;

        }
        return count;

    }

    bool doubly_linked_list::is_empty() {
        return head == nullptr;
    }

    void doubly_linked_list::append(int input) {
        node *temp = new node(input);
        tail = head;
        temp->next = nullptr;
        head = nullptr;
        if(head){
            temp->prev = nullptr;
            head = temp;
            return;
        }
        while(tail->next != nullptr){
            tail = tail->next;
        }
        tail->next = temp;
        temp->prev = tail;
        return;
    }

    void doubly_linked_list::insert(int input, unsigned int location) {
        node *temp = new node(input);
        if (location == 1) {
            temp->next = head;
            temp->prev = nullptr;
            if (head != nullptr)
                head->prev = temp;
            return;
        }
        else if (location == size()){
            lab6::doubly_linked_list::append(input);
        }
        node* temp2 = head;
        for(unsigned int i =0; i<location-2; i++){
            temp2->prev = temp;
            temp2 = temp2->next;
        }
        temp->next = temp2->next;
        temp2->next = temp;
    }

    void doubly_linked_list::remove(unsigned location) {
        node *temp;
        if(head == nullptr){
            return;
        }
        if (location == 0){
            head = temp->next;
        }
        unsigned i = 0;
        while(temp && i<location){
            temp->prev= temp;
            temp = temp->next;
            i++;
            if(!temp){
                std::cout << "Position not found. \n";
                return;
            }
            temp->prev->next = temp->next;
            free(temp);
        }

    }

    doubly_linked_list doubly_linked_list::split(unsigned position) {

    }

    doubly_linked_list doubly_linked_list::split_set(unsigned position_1, unsigned position_2) {

    }

    void doubly_linked_list::swap(unsigned position_1, unsigned position_2) {

    }

    void doubly_linked_list::swap_set(unsigned location_1_start, unsigned location_1_end, unsigned location_2_start,
                                      unsigned location_2_end) {

    }

    void doubly_linked_list::sort() {
        // Implement Insertion Sort
    }

    doubly_linked_list doubly_linked_list::operator+(const doubly_linked_list &rhs) const {

    }

    doubly_linked_list& doubly_linked_list::operator=(const doubly_linked_list &rhs) {

    }

    doubly_linked_list& doubly_linked_list::operator+=(const doubly_linked_list &rhs) {

    }

    bool doubly_linked_list::operator==(const doubly_linked_list &rhs) {

    }

    std::ostream &operator<<(std::ostream &stream, doubly_linked_list &RHS) {

    }

    std::istream &operator>>(std::istream &stream, doubly_linked_list &RHS) {

    }
}

