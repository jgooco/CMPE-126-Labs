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

void sum(int a , int b, int &c){
    a = b+c;
    b = a+c;
    c= a+b;
}

int threesome(int arr[], int size){
    int count =0;
    for (int a = 0; a < size-1; a++){
        int b = a+1;
        int c = size -1;
        while (b < c){
            if(arr[a] + arr[b] +arr[c] ==0){
                count ++;
                b ++;
            }
            else if (arr[a] + arr[b] +arr[c] <0){
                b++;
            }
            else if (arr[a] + arr[b] +arr[c] > 0){
                c--;
            }
        }
    }
    return count;
}

int binarysearch(int arr[], int size, int key){
    int first =0;
    int last = size -1;
    int middle = first + (last-first)/2;
    while (first <= last){
        if (arr[middle] == key)
            return middle;
        if (arr[middle] > key)
            last = middle-1;
        if (arr[middle] < key)
            first = middle +1;
    }
}
int main() {
    /*insert(2);
    insert(3);
    insert(4);
    print();

    int a[5] = {10, 20 ,30, 40, 50};
    std::cout<< a << std::endl;
    std::cout << *a+1 << std::endl;
    //std::cout << *(a++);
    std::cout << *(a+1)<< std::endl;


    char arr[20];
    int i;
    for (int i =0; i < 10; i++)
        *(arr+ i) = 65+i;
    *(arr+i) = '\0';
    std::cout <<arr;

    int x =2;
    int y = 3;
    sum(x, y, y);
    std::cout << x << " " << y;

    int *secret;
    secret = new int[10];
    secret[9] = 10;
    for(int j = 8; j>-1; j--)
        secret[j] = secret[j+1]+5;
    for (int j =1; j <10; j++)
        std:: cout <<secret[j] << " ";
    std:: cout << std::endl;
    */
    int size = 7;
    int array[size] = {2, 3 ,-3 ,1, -9, 6, -5};
    int output;
    output = threesome(array, size);
    std:: cout << output << " " << std:: endl;
    int key = 1;
    int arr[size] = {-1, 0, 1 ,1 ,1 ,1, 9};
    output = binarysearch(arr, size, key);
    std:: cout << output << " " << std:: endl;







    return 0;
}

