#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include "treenode.h"
#include "datainput.h"

class BinarySearchTree {
    public:
        BinarySearchTree();
        ~BinarySearchTree();
        void del_tree(TreeNode* root);
        void insert(std::string decoded, std::string encoded);
        void cipher_input(std::ifstream& in_file);
        void find_encoded(std::string& return_value, std::string char_value);
        void find_encoded(TreeNode*& parent, std::string& return_value, std::string char_value);
        void print() const;
    private:
        void print(TreeNode* parent) const;
        void add_node(TreeNode* parent, TreeNode* new_node) const;
        TreeNode* root;
};

#endif