#include "prompt.h"

void welcome_statement() {
    char choice;
    std::cout << "Hello! This program uses binary search trees or hash tables to encode or decode the"
              << " the text file in the folder directory." << std::endl;
    std::cout << "Would you like to continue(Y/n):" ;
    std::cin >> choice;
    if (choice == 'Y' || choice == 'y') {
        std::string filename;
        std::cout << std::endl << "Enter the name of the file (please add .txt):"; 
        std::cin >> filename;
        read_file(filename); 
    }
    else if (choice == 'N' || choice == 'n') {
        exit(0);
    }
}

void custom_file() {
    char choice;
    std::cout <<  std::endl << "Output has been saved. Would you like to re-use the program?(Y/n):" ; 
    std::cin >> choice;
    if (choice == 'Y' || choice == 'y') {
        std::string filename;
        std::cout << std::endl << "Enter the name of the file (please add .txt):";
        std::cin >>filename;
        read_file(filename);
        return ;
    }
    else if (choice == 'N' || choice == 'n') {
        std::cout << std::endl << "Thanks for using program!!!";
        return ;
    }       
}



