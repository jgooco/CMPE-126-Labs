#include "../inc/tree.h"
#include <iostream>

namespace lab7 {
    void clear(node *to_clear);

    void insert_recurse(node *top, int value);
    unsigned size_recurse(node *top);
    int level_recurse(node *top, int key);
    unsigned depth_recurse(node* top);
    bool in_tree_recurse(node *top, int key);
    int get_frequency_recurse(node* top, int key);
    void path_recur(node *top, int key);
    void print_recur(node *top);
    node *get_node(node * top, int key);
    node *get_parent(node *top, node *child);
    bool children_exist(node *check);
    node *get_swap(node * top);


    // Construct an empty tree
    tree::tree() {
        root = nullptr;
        tree_size = 0;
    }

    // Copy constructor
    tree::tree(const tree &copy) {

    }

    // Deconstruct tree
    tree::~tree() {
        clear(root);
    }

    // Insert
    void tree::insert(int value) {
        if(root == nullptr){
            root = new node(value);
        }
        else{
            insert_recurse(root, value);
        }
    }

    //Recursive Insert
    void insert_recurse(node *top, int value){
        if( value > top->data )
        {
            if( top->right == nullptr ) top->right = new node(value);
            else insert_recurse( top->right, value);
        }
        else if( value < top->data )
        {
            if( top ->left == nullptr ) top->left = new node(value);
            else insert_recurse(top->left, value);
        }
        else if( value == top->data ) top->frequency++;
    }

    // Remove key return true if the key is deleted, and false if it isn't in the tree
    bool tree::remove(int key) {
        if(in_tree(key)){
            node *remove = get_node(root, key);
            if(remove->frequency >1 ){
                remove->frequency --;
                return true;
            }
            node * remove_parent= get_parent(root, remove);
            if(children_exist(remove)){
                node * swap = get_swap(remove);
                node * swap_parents= get_parent(root, swap);
                if(children_exist(swap))
                    swap_parents->right = swap->left;
                else
                    swap_parents->right = nullptr;
                swap->left= remove->left;
                swap->right= remove->right;
                if(remove_parent != nullptr){
                    if(remove_parent->left == remove)
                        remove_parent ->left = swap;
                    else
                        remove_parent->right = swap;
                }
                else
                    root = swap;
            }
            else{
                if(remove_parent != nullptr){
                    if(remove_parent ->left == remove)
                        remove_parent->left = nullptr;
                    else
                        remove_parent->right = nullptr;
                }
                else
                    root = nullptr;
            }
            delete remove;
            return true;
        }
        else return false;
    }

    node *get_node(node * top, int key){
        if(top->data == key)
            return top;
        else if (key<top->data)
            return get_node(top->left, key);
        else  if (key>top->data)
            return get_node(top->right, key);
    }

    node *get_parent(node *top, node *child){
        if(top == child)
            return nullptr;
        else if (top->left == child || top->right == child)
            return top;
        else if (child->data < top->data)
            return get_parent(top->left, child);
        else if  (child->data > top->data)
            return get_parent(top->right, child);
    }

    bool children_exist(node *check){
        if(check->left != nullptr || check->right != nullptr)
            return true;
        else return false;
    }

    node *get_swap(node * top){
        if(top->left){
            top = top->left;
            while(top->right)
                top = top->right;
            return top;
        }
        else{
            top = top->right;
            return top;
        }
    }

    // What level is key on?
    int tree::level(int key) {
        if(in_tree(key))
            return level_recurse(root, key);
        else
            return -1;
    }

    int level_recurse(node *top, int key){
        if(top->data == key)
            return 0;
        else if (key<top->data)
            return 1 + level_recurse(top->left, key);
        else if(key>top->data)
            return 1 + level_recurse(top->right, key);
    }

    // Print the path to the key, starting with root
    void tree::path_to(int key) {
        if(in_tree(key))
            path_recur(root, key);
    }

    void path_recur(node *top, int key){
        std::cout << top->data;
        if(top->data == key){
            std::cout << std::endl;
            return;
        }
        else{
            std::cout << " -> ";
            if (key < top->data)
                path_recur(top->left, key);
            else
                path_recur(top->right, key);
        }
    }

    // Number of items in the tree
    unsigned tree::size() {
        if(root == nullptr)
            return 0;
        else
            return size_recurse(root);

    }

    unsigned size_recurse(node *top){
        if(top == nullptr)
            return 0;
        else
            return top->frequency + size_recurse(top->left) + size_recurse(top->right);
    }

    // Calculate the depth of the tree, longest string of connections
    unsigned tree::depth() {
        if( size() <= 1)
            return 0;
        else
            return depth_recurse(root) - 1;
    }

    unsigned depth_recurse(node* top){
        if(top == nullptr)
            return 0;
        unsigned  left = 0, right = 0;
        left = 1+ depth_recurse(top->left);
        right = 1 + depth_recurse(top->right);
        if(left > right)
            return left;
        else
            return  right;
    }

    // Determine whether the given key is in the tree
    bool tree::in_tree(int key) {
        return in_tree_recurse(root, key);
    }

    bool in_tree_recurse(node *top, int key){
        if(top == nullptr)
            return false;
        else if(top->data == key)
            return true;
        else if(key< top->data)
            return in_tree_recurse(top->left, key);
        else if(key>top->data)
            return in_tree_recurse(top->right, key);
    }

    // Return the number of times that value is in the tree
    int tree::get_frequency(int key) {
        return get_frequency_recurse(root, key);
    }

    int get_frequency_recurse(node* top, int key){
        if(top == nullptr)
            return 0;
        else if (top->data == key)
            return top->frequency;
        else if (top->data < key)
            return get_frequency_recurse(top->right, key);
        else if (top->data > key)
            return get_frequency_recurse(top->left, key);
    }

    // Return a string of all of the elements in the tree in order
    std::string tree::to_string() {

    }

    //Use the to string function for the following two functions
    // Print the tree least to greatest, Include duplicates
    void tree::print() {
        print_recur(root);
        std::cout<< std::endl;
    }

    void print_recur(node *top){
        if(top == nullptr)
            return;
        print_recur(top->left);
        for(int i = 0; i< top->frequency; i++){
            std:: cout << top->data << " ";
        }
        print_recur(top->right);

    }

    // Print the tree least to greatest, Include duplicates
    std::ostream &operator<<(std::ostream &stream, tree &RHS) {

    }

    // Operator= Overload. Allowing for copying of trees
    tree &tree::operator=(const tree &rhs) {

    }

    /**************************
     * Extra credit functions *
     **************************/

    // Return a vector with all of the nodes that are greater than the input key in the tree
    std::vector<int> tree::values_above(int key) {

    }

    // Merge rhs into this. Demo to a TA for credit
    tree tree::operator+(const tree &rhs) const {

    }

    // Balance the tree using any published algorithm. Demo to a TA for credit
    void tree::balance() {

    }

    /*********************************************************************
     * Recursion Example                                                 *
     * Print the linked list from greatest to least using recursion      *
     *********************************************************************/

    // Auxiliary functions
    void node_print_gtl(node *top) {
        if (top == nullptr) return;
        node_print_gtl(top->right);
        for (int i = 0; i < top->frequency; i++) std::cout << top->data << " ";
        node_print_gtl(top->left);
    }

    void clear(node *to_clear) {
        if (to_clear == nullptr) return;
        if (to_clear->left != nullptr) clear(to_clear->left);
        if (to_clear->right != nullptr) clear(to_clear->right);
        delete to_clear;
    }

    // Class function
    void tree::print_gtl() {
        node_print_gtl(root);
        std::cout << std::endl;
    }
}