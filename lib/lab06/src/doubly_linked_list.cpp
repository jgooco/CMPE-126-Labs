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
        auto *temp = new node(input);
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
        if(head == nullptr || location <= 0)
            return;
        node *current = head;

        for(unsigned int i = 1; current != nullptr && i < location; i++)
            current = current->next;
        if(current == nullptr)
            return;
        deletenode(current);
    }

    doubly_linked_list doubly_linked_list::split(unsigned position) {

    }

    doubly_linked_list doubly_linked_list::split_set(unsigned position_1, unsigned position_2) {

    }

    void doubly_linked_list::swap(unsigned position_1, unsigned position_2) {
        unsigned temp;
        temp = position_1;
        position_1 = position_2;
        position_2 = temp;
        delete temp;
    }

    void doubly_linked_list::swap_set(unsigned location_1_start, unsigned location_1_end, unsigned location_2_start,
                                      unsigned location_2_end) {

    }

    void doubly_linked_list::sort() {
        node *sorted = nullptr;
        node *current = head;
        while(current != nullptr){
            node* next = current ->next;
            current->prev = current->next = nullptr;
            sortedinsert(current);
            current = next;

        }
        head = sorted;
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

    void doubly_linked_list::deletenode(node *del){
        if(head == nullptr || del == nullptr)
            return;
        if(head == del)
            head = del->next;
        if(del->next != nullptr)
            del->next->prev = del->prev;
        if(del->prev != nullptr)
            del->prev->next = del->next;
        free(del);

    }

    void doubly_linked_list::sortedinsert(node *new_node){
        node* current;
        if (head == nullptr)
            head = new_node;
        else if (head ->get_data() >= new_node->get_data()) {
            new_node->next = head;
            new_node->next->prev = new_node;
            head = new_node;
        }
        else{
            current = head;
            while(current->next != nullptr && current->next->get_data() < new_node->get_data())
                current = current->next;
            new_node->next = current->next;
            if(current->next != nullptr)
                new_node->next->prev = new_node;
            current->next = new_node;
            new_node->prev = current;
        }
    }


}

