#include "../inc/hash_table.h"

namespace lab8{
    unsigned hash_table::hash_1(std::string to_hash) {

        unsigned int hash = 5381;
        for(char c: to_hash){
            hash = ((hash << 5) + hash) + c;
        }
        return hash;
    }

    unsigned hash_table::hash_2(std::string to_hash) {

        unsigned int seed = 131;
        unsigned int hash = 0;
        for(char c: to_hash){
            hash = (hash * seed) + c;
        }
        return hash;
    }

    void hash_table::expand() {
        // Expand the hash table by a factor of 2 every time this function is called


        //max_size = max_size * 2;

        for(int i = 0; i < 16; i++){
            if( max_size < PRIMES[i]){
                max_size = (unsigned int) PRIMES[i];
                break;
            }
        }

        //Create new empty table doubled
        key_value *oldTable = hash_table_array;
        hash_table_array = new key_value[max_size];

        //Copy all the elements in the old table to the new table
        int oldCurrentSize = current_size;
        current_size = 0;

        for(int i = 0; i < oldCurrentSize; i++){
            insert(oldTable[i].key, oldTable[i].value);
        }
        delete [] oldTable;
    }

    hash_table::hash_table(char type) {
        /*
         * Define the probing technique
         * 'l': Linear probing
         *          hash_1() + attempt
         * 'q': Quadratic probing
         *          hash_1() + attempt^2
         * 'd': Double Probing
         *          hash_1() + attempt * hash_2()
         *
         * Create a hash table with an initial size of 100
         */

        probing = type;
        max_size = PRIMES[0];
        current_size = 0;
        hash_table_array = new key_value[max_size];

    }

    hash_table::~hash_table() {
        delete [] hash_table_array;
    }


    bool hash_table::insert(std::string key, int value) {
        if(in_table(key))
            return false;
        unsigned hash = (hash_1(key)) % max_size;
        unsigned attempt = 1;

        while(!hash_table_array[hash].key.empty() and hash_table_array[hash].key != key) {
            if(probing == 'l')
                hash++;
            else if(probing == 'q')
                hash = (hash + attempt*attempt);
            else if(probing == 'd')
                hash = (hash + attempt*hash_2(key));
            attempt ++;
            hash %= max_size;
        }
        if(hash_table_array[hash].key == "") {
            current_size++;
        }
        hash_table_array[hash].key = key;
        hash_table_array[hash].value = value;
        if(current_size/max_size > 0.7) expand();
        return true;
    }

    bool hash_table::in_table(std::string key){
        // Checks to see if that key is in the table.
        // Use the specified probing technique
        // Keep collisions in mind
        unsigned hash = hash_1(key) % max_size;
        unsigned attempt = 1;
        while(hash_table_array[hash].key != "") {
            if(hash_table_array[hash].key == key)
                return true;
            if(probing == 'l')
                hash ++;
            else if(probing == 'q')
                hash = (hash + attempt*attempt);
            else if(probing == 'd')
                hash = (hash + attempt * hash_2(key));
            attempt ++;
            hash %= max_size;
        }
        return false;
    }

    int hash_table::get(std::string key) {
        // Get the int value from the node that has key
        // Use the specified probing technique
        unsigned hash = hash_1(key) % max_size;
        unsigned attempt = 1;
        while(hash_table_array[hash].key != "") {
            if(hash_table_array[hash].key == key)
                return hash_table_array[hash].value;
            if(probing == 'l')
                hash ++;
            else if(probing == 'q')
                hash = (hash + attempt*attempt);
            else if(probing == 'd')
                hash = (hash + attempt * hash_2(key));
            attempt ++;
            hash %= max_size;
        }
        throw std::exception();
    }

    void hash_table::update(std::string key, int value){
        // Update a key in the hash table.
        // Keep collisions in mind
        // Use the specified probing technique

        unsigned hash = hash_1(key) % max_size;
        unsigned attempt = 1;
        while(hash_table_array[hash].key != "") {
            if(hash_table_array[hash].key == key) {
                hash_table_array[hash].value = value;
                return;
            }
            if(probing == 'l')
                hash ++;
            else if(probing == 'q')
                hash = (hash + attempt*attempt);
            else if(probing == 'd')
                hash = (hash + attempt * hash_2(key));
            attempt ++;
            hash %= max_size;
        }
        insert(key, value);
    }

    void hash_table::remove(std::string key){
        // Remove an item from the hash table. Keep collisions in mind
        // Use the specified probing technique
        // If the item isn't in the table, do nothing.

        unsigned hash = hash_1(key) % max_size;
        unsigned attempt = 1;
        while(hash_table_array[hash].key != "") {
            if(hash_table_array[hash].key == key) {
                current_size--;
                hash_table_array[hash].key = "";
            }
            if(probing == 'l')
                hash ++;
            else if(probing == 'q')
                hash = (hash + attempt*attempt);
            else if(probing == 'd')
                hash = (hash + attempt * hash_2(key));
            attempt ++;
            hash %= max_size;
        }

    }

    std::string hash_table::to_string(){
        // Run through the entire array and create a string following this format. The {} brackets aren't part of the return
        // [{array location}]{key_value.key}:{key_value.int}

        return std::string();
    }
}