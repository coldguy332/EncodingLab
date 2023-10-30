#ifndef TREENODE_H
#define TREENODE_H

#include <iostream>

struct TreeNode{
    std::string decoded;
    std::string encoded;
    TreeNode* left = nullptr;
    TreeNode* right = nullptr;
};

#endif