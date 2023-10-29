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

    //test.get_data();
   
   
    return 0;
}