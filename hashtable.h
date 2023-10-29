#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "hashnode.h"

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
        /**
         * Inserts encoded value into hash table
         * @param decode this string will be used to make the hash code
         * @param encode this string will be stored in array under that hash code
        */
        void insert(const std::string& decode, const std::string& encode);
    private:
        HashNode *arr[50]; 
};

#endif