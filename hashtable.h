// Created by Amal Afsal for Encoding lab on 10/28/23.

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
 * Takes in a string and creates an array position to be stored at
 * Ripped from zybooks
 * @https://learn.zybooks.com/zybook/OHLONECS124ChenhansaFall2023/chapter/16/section/5
*/
int hash_code(const std::string& decode);

/**
 * Hash Table class that will be used to decode (ex: 00 to a)
*/
class HashTable {
    public:
        /**
         * Default constructor that sets all ptrs of hashtable to null
        */
        HashTable();
        /**
         * Destructor for hash table objects
        */
        ~HashTable();

        /**
         * Inserts encoded value into hash table
         * @param decode decoded value to be stored in hash table
         * @param encode encoded value to be stored in hash table
        */
        void insert(const std::string& decode, const std::string& encode);
        /**
         * Inputs cipher data into hash table
         * @param in_file filestream that holds cipher text file
        */
        void cipher_input(std::ifstream& in_file);

        /**
         * @return a decoded value for every encoded value
        */
        std::string find_decoded(std::string encoded_value);
    private:
        HashNode *arr[50]; 
};

#endif