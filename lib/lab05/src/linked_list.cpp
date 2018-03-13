#include <linked_list.h>
namespace lab5 {
    linked_list::linked_list() {
        head = nullptr;
        tail = nullptr;

    }

    linked_list::linked_list(std::string &data) {
        head= new node(data);
        append(data);



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
        if (head)
            return false;
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
        node *temp = new node(input);
        temp->data = input;
        temp->next = nullptr;
        if(location == 1){
            temp->next = head;
            head = temp;
            return;
        }

        node* tmp = head;
        while(tmp->next != NULL){
            tmp = tmp->next;
        }
        temp->next = tmp->next;
        tmp->next = temp;
        return;
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

    std::string linked_list::get_value_at(unsigned location) {

    }
    //AUX functions

    static void swap_nodes(node** head_ref, node* x, node* y, node* prevy){
        *head_ref = y;
        node* temp = y->next;
        y->next = x->next;
        x->next = temp;
    }

}