#include "prompt.h"

void welcome_statement() {
    char choice;
    std::cout << "Hello! This program uses binary search trees or hash tables to encode or decode the"
              << " the text file in the folder directory." << std::endl;
    std::cout << "Would you like to continue(Y/n):" ;
    std::cin >> choice;
}