#include <iostream>

struct Node{
    int data;
    Node*next;
};
Node *head;

void insert(int d){
    Node*tmp= new Node();
    tmp->data = d;
    tmp->next = NULL;

    if(head==NULL){
        head = tmp;
        return;
    }
    Node* tmp1 = head;
    while(tmp1->next != NULL)
    {
        tmp1= tmp1->next;
    }
    tmp1->next = tmp;
    return;

}

void print(){
    Node* tmp1 = head;
    while(tmp1->next != NULL){
        std::cout <<tmp1->data<< " ";
        tmp1 = tmp1->next;
    }
    std::cout<<tmp1->data<<std::endl;
    return;
}
int main() {
    insert(2);
    insert(3);
    insert(4);
    print();




    return 0;
}