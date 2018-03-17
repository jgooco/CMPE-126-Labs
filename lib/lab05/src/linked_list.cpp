#include <linked_list.h>
#include <assert.h>
#include <iostream>
namespace lab5 {
    linked_list::linked_list() {
        head = nullptr;
        tail = nullptr;
    }

    linked_list::linked_list(std::string &data) {
        head= new node(data);
        tail= head;
        append(data);
    }

    linked_list::linked_list(const linked_list &original) {
        (*this) = original;

    }

    linked_list::~linked_list() {
        node* current = head;
        node* next;
        while(current != nullptr){
            next = current->next;
            delete current;
            current = next;
        }
        head  = nullptr;


    }

    linked_list &lab5::linked_list::operator=(const linked_list &RHS) {

        //return <#initializer#>;
    }


    bool linked_list::isEmpty() const {
        if (head)
            return false;
        else
            return true;
    }

    unsigned linked_list::listSize() const {
        node* current = head;
        unsigned int count =0;
        while(current != nullptr){
            count ++;
            current = current->next;

        }
        return count;
    }

    void linked_list::insert(const std::string input, unsigned int location) {
        node* temp1 = new node(input);
        temp1->data = input;
        temp1->next = nullptr;
        if(location == 1){
            temp1->next = head;
            head = temp1;
            return;
        }
        if(location == listSize()){
            lab5::linked_list::append(input);
        }
        node* temp2 = head;
        for(unsigned int i =0; i<location-2; i++){
            temp2 = temp2->next;
        }
        temp1->next = temp2->next;
        temp2->next = temp1;
    }

    void linked_list::append(const std::string input) {
        node *temp = new node(input);
        if(head==nullptr){
            head = temp;
            tail = head;
            return;
        }
        if(tail != nullptr) {
            tail->next = temp;
            tail = tail->next;
            return;
        }

        if(tail == nullptr){
            tail = temp;
            temp->next = nullptr;
            tail->next = temp->next;
            return;
        }
    }

    void linked_list::remove(unsigned location) {
        node *temp = head, *prev = nullptr;
        if(temp == nullptr)
            return;
        if(location == 0){
            head = temp->next;
            free(temp);
            return;
        }
        unsigned i = 0;
        while(temp && i<location){
            prev= temp;
            temp = temp->next;
            i++;
            if(!temp){
                std::cout << "Position not found. \n";
                return;
            }
            prev->next = temp->next;
            free(temp);
        }

        /*node *curr;
        node *prev;
        curr = head;
        for(int i =1; i<location; i++){
            prev= curr;
            curr = curr->next;
        }
        prev->next=curr->next;
         */

    }

    std::ostream& operator<<(std::ostream &stream, linked_list &RHS) {
        return stream;
    }

    std::istream& operator>>(std::istream &stream, linked_list &RHS) {
        return stream;
    }
    static void swap_nodes(node** head_ref, node* x, node* y, node* prevy){ //AUX function
        *head_ref = y;
        node* temp = y->next;
        y->next = x->next;
        x->next = temp;
    }


    node* selection_sort(node *head){ //AUX function
        if(head->next == NULL)
            return head;
        node* min = head;
        node* before_min = NULL;
        node* ptr;

        for(ptr=head; ptr->next != NULL; ptr = ptr->next){
            if(ptr->next->data < min->data){
                min = ptr->next;
                before_min = ptr;
            }
        }
        if(min != head){
            swap_nodes(&head, head, min, before_min);
        }

        head->next = selection_sort(head->next);

        return head;
    }

    void linked_list::sort() {
        node** head_ref;
        if((*head_ref) == NULL)
            return;
        *head_ref = selection_sort(*head_ref);

    }

    std::string linked_list::get_value_at(unsigned location) const {
        node* current = head;
        unsigned int count = 0;
        while(current != nullptr){
            if(count == location)
                return(current->data);
            count++;
            current = current->next;
        }

    }
    //AUX functions


}