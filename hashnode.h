#ifndef HASHNODE_H
#define HASHNODE_H

#include <iostream>

/**
 * Assuming collisions occur, going to use bucket method
 * Will be two separate nodes in general from hash table and tree
 * Hash node needs a next ptr while tree needs left&right ptr
*/
struct HashNode{
    std::string decoded;
    std::string encoded;
    HashNode* next = nullptr;
};



#endif