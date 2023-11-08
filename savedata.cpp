// Created by Amal Afsal for Encoding lab on 10/29/23.

#include "savedata.h"

void output_data(std::string a, std::string b) {
    std::ofstream out_file; //Creates an ofstream
    out_file.open("output.txt"); //txt to be saved by will be named output.txt
    out_file << a << std::endl << std::endl << b; //ofstream will both encoded and decoded string to a txt
    /*Note: I've given lazy names to both strings because the program will save the text in a particular order 
      depending on if it was encoded or decoded. 
      ex: if program decoded, 'a' will store the original encoded text, 'b' will store the decoded text
      ex: if program encoded, 'a' will store the original decoded text, 'b' will store the encoded text
      it's either one or the other
    */
}