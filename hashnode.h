#ifndef HASHNODE_H
#define HASHNODE_H

#include <iostream>

/**
 * Node that will be stored in hashtable
*/
struct HashNode{
    //Extra string needed to return the right value 
    //(ex: if encoded == node->encoded , return 'e')
    std::string decoded; //This will hold a decoded value
    std::string encoded; //This will hold an encoded value
    HashNode* next = nullptr;
};



#endif