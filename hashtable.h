#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>

#include "hashnode.h"
#include "datainput.h" //Primarily for linecounter

const int INDEX = 50; //Hash table size is 50

/**
 * Hash code function that will provide index for hash table
*/
int hash_code(const std::string& decode);

/**
 * Hash Table that will encode (A to 00)
*/
class HashTable {
    public:
        /**
         * Default constructor that sets all ptrs of hashtable to null
        */
        HashTable();
        ~HashTable();

        void get_data() const;

        /**
         * Inserts encoded value into hash table
         * @param decode this string will be used to make the hash code
         * @param encode this string will be stored in array under that hash code
        */
        void insert(const std::string& decode, const std::string& encode);
        void cipher_input(std::ifstream& in_file);

        std::string find_decoded(std::string value);
    private:
        HashNode *arr[50]; 
};

#endif