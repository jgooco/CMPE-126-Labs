#ifndef CMPE126S18_LABS_TREE_H
#define CMPE126S18_LABS_TREE_H
#include "node.h"
#include <iostream>

namespace lab7 {
    class tree {
        node *root;
    public:
        tree();
        tree(const tree& copy);
        ~tree();

        void insert(int value);
        bool remove(int key);
        bool in_tree(int key);
        int get_frequency(int key);

        int level(int key);
        void path_to(int key);
        unsigned size();
        unsigned depth();
        void print();

        tree& operator=(const tree &rhs);
        friend std::ostream& operator<<(std::ostream& stream, tree& RHS);

        // Extra credit
        tree operator+(const tree &rhs) const;
        void balance();

        // Example recursion
        void print_gtl();
    };
}

#endif //CMPE126S18_LABS_TREE_H
