// Created by Amal Afsal for Encoding lab on 10/29/23.

#ifndef TREENODE_H
#define TREENODE_H

#include <iostream>

/**
 * Node that will be stored in binary search tree
*/
struct TreeNode{
    //Extra string needed to return the right value 
    //(ex: if decoded == node->decoded , return "0010")
    std::string decoded;
    std::string encoded;
    TreeNode* left = nullptr;
    TreeNode* right = nullptr;
};

#endif