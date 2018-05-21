#include "doubly_linked_list.h"

namespace lab6{
    // Auxiliary Functions
    unsigned partition(int* to_sort, int low, int high);
    void shuffle(int a[], int length);
    void sort(int a[], int lo, int hi);

    doubly_linked_list recursive_merge_sort(doubly_linked_list to_sort);
    doubly_linked_list merge(doubly_linked_list left, doubly_linked_list right);

    void quicksort(int* to_sort, int low, int high){
        int length = rand();
        shuffle(to_sort, length);
        sort (to_sort, 0, length-1);
    }

    unsigned partititon(const int* to_sort, int low, int high){
        int i = low, j = high +1;
        while (1){
            while(to_sort[++i] < to_sort[low])
                if(i==high) break;
            while (to_sort[low] < to_sort[--j])
                if(j==low) break;
            if(i>=j) break;
            int temp;
            temp = i;
            i = j;
            j = temp;
            delete temp;
        }
        int temp;
        temp = low;
        low = j;
        j= temp;
        delete temp;
        return static_cast<unsigned int>(j);

    }

    void shuffle(int a[], int alen){
        for(int i =0; i<alen; i++){
            int r = rand() % (i+1);
            int a;
            a = i;
            i = r;
            r = a;
            delete a;
        }
    }

    void sort(int a[], int lo, int hi){
        if (hi <= lo) return;

        int j = partition(a, lo, hi);
        sort(a, lo, j-1);
        sort(a, j+1, hi);
    }

    void mergesort(doubly_linked_list& to_sort){

    }

    doubly_linked_list recursive_merge_sort(doubly_linked_list to_sort){

    }

    //Used for the merging the two lists
    doubly_linked_list merge(doubly_linked_list left, doubly_linked_list right){

    }
}