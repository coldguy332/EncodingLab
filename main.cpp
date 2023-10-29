#include <iostream>
#include <fstream>

#include "prompt.h"
#include "hashtable.h"
#include "datainput.h"

int main() {
    //welcome_statement();
    HashTable test;
    std::ifstream in_file;
    in_file.open("cipher-1.txt");
    int index = line_counter(in_file);
    
    test.cipher_input(in_file,index);

    std::string a = "Success";
    std::string c = "is";
    std::string b = test.find_encoded(a);
    std::string d = test.find_encoded(c);
   
    std::cout << b << d << std::endl;

    return 0;
}