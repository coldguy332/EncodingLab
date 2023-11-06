#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include "treenode.h"
#include "datainput.h"

class BinarySearchTree {
    public:
        /**
         * Default constructor for binary search tree
        */
        BinarySearchTree();
        /**
         * User-define destructor for binary search tree
        */
        ~BinarySearchTree();
        /**
         * Helper function to object destructor
        */
        void del_tree(TreeNode*& root);
        /**
         * Creates new treenode, and inserts into binary search tree
         * treenode will hold a decoded value for every encoded value
         * ex: e,0
         * Helper to cipher_input function
         * @param decoded newnode will hold a decoded value (ex: "a")
         * @param encoded newnode will hold an encoded value (ex: 00)
        */
        void insert(std::string decoded, std::string encoded);
        /**
         * Function that reads in cipher and creates binary search tree based on it
         * @param in_file filestream that takes in from the cipher
        */
        void cipher_input(std::ifstream& in_file);
        /**
         * Helper function that calls on function below to converted decoded to encoded
         * @param return_encoded string passed by reference which will hold encoded values as program encrypts
         * @param decoded_value decoded value (ex: "A") that program uses to find the appropriate encoded value
        */
        void find_encoded(std::string& return_encoded, std::string decoded_value);
        /**
         * Function that finds an encoded value for its associated decoded value
         * @param parent root of subtrees which hold data
         * @param return_encoded stores encoded values
         * @param decoded_value decoded value (ex: "A") that program uses to find the appropriate encoded value
        */
        void find_encoded(TreeNode*& parent, std::string& return_encoded, std::string decoded_value);
    private:
        /**
            Inserts a new node as a descendant of a given node.
            @param parent the root node
            @param new_node the node to insert
            @https://learn.zybooks.com/zybook/OHLONECS124ChenhansaFall2023/chapter/17/section/4
        */
        void add_node(TreeNode*& parent, TreeNode*& new_node);
        TreeNode* root;
};

#endif