#include "binarysearchtree.h"

BinarySearchTree::BinarySearchTree() {
    this->root = nullptr;
}

BinarySearchTree::~BinarySearchTree() {
    del_tree(root);
}

void BinarySearchTree::del_tree(TreeNode* root) {
    if (root == nullptr) {
        return ;
    }
    else {
        TreeNode* del = root;
        TreeNode* left = root->left;
        TreeNode* right = root->right;
        delete del;
        del_tree(left);
        del_tree(right);
    }
}

void BinarySearchTree::insert(std::string decoded, std::string encoded) {
    TreeNode* new_node = new TreeNode;
    new_node->decoded = decoded;
    new_node->encoded = encoded;
    if (root == nullptr) {root = new_node;}
    else { add_node(root, new_node);}
}

void BinarySearchTree::cipher_input(std::ifstream& in_file) {
    int num_of_lines = line_counter(in_file);
    std::string temp_line;
    std::string temp_encode;
    std::string temp_decode;
    for (int i = 0; i < num_of_lines; i++) {
        getline(in_file,temp_line);
        std::stringstream ss;
        ss.str(temp_line);
        getline(ss, temp_decode, '\t');
        getline(ss, temp_encode);

        this->insert(temp_decode,temp_encode);
    }
    in_file.clear(); //Resets error flags on a stream such as EOF
	in_file.seekg(0);//sets position of next character to be read back to beginning of file
}

std::string BinarySearchTree::find_encoded(std::string decoded) {
    std::string return_value = "";
    for (int i = 0; i < decoded.size(); i++) {
        std::string char_value(1,decoded[i]);
        TreeNode* current = this->root;
        while (current != nullptr) {
            if (char_value < current->decoded) {
                current = current->left;
            }
            else if (char_value > current->decoded) {
                current = current->right;
            }
            else {
                break;
            }
        }
        if (i != decoded.size() - 1) {
            return_value += current->encoded + " ";
        }
        else {
            return_value += current->encoded + "  ";
        }
    }
    return return_value;
}

void BinarySearchTree::print() const {
    print(this->root);
    std::cout << std::endl;
}



void BinarySearchTree::print(TreeNode* parent) const {
    if (parent == nullptr) {return;}
    print(parent->left);
    std::cout << parent->decoded << " " << parent->encoded << " " << std::endl;
    print(parent->right);
}

void BinarySearchTree::add_node(TreeNode* parent, TreeNode* new_node) const {
    if (new_node->decoded < parent->decoded) {
        if (parent->left == nullptr) {parent->left = new_node;}
        else {add_node(parent->left, new_node);}
    }
    else if (new_node->decoded > parent->decoded) {
        if (parent->right == nullptr) {parent->right = new_node;}
        else {add_node(parent->right, new_node);}
    }
}