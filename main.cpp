#include <iostream>
#include <fstream>

#include "prompt.h"
#include "hashtable.h"
#include "datainput.h"

int main() {
    /**
     * Program runs function from these files typically in this order
     * prompt.h
     * datainput.h
     * hashtable.h or binarysearchtree.h
     * savedata.cpp
     * back to prompt.h
    */
    welcome_statement(); //from prompt.h
    return 0;
}