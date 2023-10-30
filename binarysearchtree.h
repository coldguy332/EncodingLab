#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include "treenode.h"
#include "datainput.h"

class BinarySearchTree {
    public:
        BinarySearchTree();
        void insert(std::string decoded, std::string encoded);
        void cipher_input(std::ifstream& in_file);
        std::string find_encoded(std::string decoded);
        void print() const;
    private:
        void print(TreeNode* parent) const;
        void add_node(TreeNode* parent, TreeNode* new_node) const;
        TreeNode* root;
};

#endif