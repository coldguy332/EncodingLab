#include "binarysearchtree.h"


BinarySearchTree::BinarySearchTree() {
    this->root = nullptr;
}

BinarySearchTree::~BinarySearchTree() {
    del_tree(root); 
}

void BinarySearchTree::del_tree(TreeNode*& root) {
    if (root == nullptr) { // if node is null, return
        return ;
    }
    else {
        del_tree(root->left); //recursively deletes roots of left and right subtrees
        del_tree(root->right); //deletes in post order
        delete root;
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
    int num_of_lines = line_counter(in_file); //Counts number of lines in the cipher
    std::string temp_line; //Will store line in txt file
    std::string temp_encode; //Will store an encoded value (ex: "0010")
    std::string temp_decode; //Will store a decoded value (ex: 'A')
    for (int i = 0; i < num_of_lines; i++) { //Loop that cycles until the end of file
        getline(in_file,temp_line); //stores lines into the temp line
        std::stringstream ss; //stringstream necessary to parse the line
        ss.str(temp_line); //stringstream takes in the value of the templine
        getline(ss, temp_decode, '\t'); //stores decoded value into temp_decode
        getline(ss, temp_encode); //stores encoded value into temp_encode

        this->insert(temp_decode,temp_encode); //Creates newnode with this data and inserts into binary tree
    }
    in_file.clear(); //Resets error flags on a stream such as EOF
	in_file.seekg(0);//sets position of next character to be read back to beginning of file
}

void BinarySearchTree::find_encoded(std::string& return_encoded, std::string decoded_value) {
    std::string encode = ""; //This string will hold the encoded value derived from the decoded value
    find_encoded(this->root, encode, decoded_value); //This function will return a value to string encode
    if (encode.empty()) {  //If string encode, or no encoded value could be found (meaning not in cipher)
        return_encoded += "?"; //program outputs a question mark to return_encoded, signifying a missing value

        /* Instead of creating a new cipher file, I just wanted to append to the original cipher.
        To make sure that there is no duplicate values, "!find_specific_decoded_value(decoded_value)" is a boolean
        function from datainput.h that checks if the decoded_value already exists  */

        if (!find_specific_decoded_value(decoded_value)) { //If decoded_value doesn't exist
            std::cout << std::endl << "Not in cipher: " << decoded_value << std::endl;
            std::ifstream in;
            std::ofstream off;
            in.open("cipher-1.txt");
            int encode = find_last_encoded_value(in); //Finds the last encoded value in the cipher (''' = 10111)
            in.close();
            off.open("cipher-1.txt" , std::ios::app); //Opens the cipher, but appends to it instead of creating a new cipher

            //saves the new decoded value, its encoded value will just be previous last encoded value + 1
            off << std::endl << decoded_value << '\t' << encode + 1 ; 
            off.close();
        }
    }
    else { //return_encoded is set to the found encoded value
        return_encoded += encode;
    }
}

void BinarySearchTree::find_encoded(TreeNode*& parent,std::string& return_encoded, std::string decoded_value) {
    if (parent == nullptr) { //Checks if parent is valid
        return ;
    }
    find_encoded(parent->left, return_encoded, decoded_value);
    if (decoded_value == parent->decoded) { //if the decoded value matches decoded value in parent node
        return_encoded += parent->encoded;  //return value that continuously adds encoded values
        return ; //Breaks out of recursion
    }
    find_encoded(parent->right, return_encoded, decoded_value);
}

/*
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

*/


void BinarySearchTree::add_node(TreeNode*& parent, TreeNode*& new_node)  {
    if (new_node->decoded < parent->decoded) {
        if (parent->left == nullptr) {parent->left = new_node;}
        else {add_node(parent->left, new_node);}
    }
    else if (new_node->decoded > parent->decoded) {
        if (parent->right == nullptr) {parent->right = new_node;}
        else {add_node(parent->right, new_node);}
    }
}