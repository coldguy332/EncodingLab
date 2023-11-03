#ifndef DATAINPUT_H
#define DATAINPUT_H

#include <fstream>
#include <sstream>

#include "prompt.h"
#include "hashtable.h"
#include "binarysearchtree.h"
#include "savedata.h"

/**
 * Function counts how many rows are in the file
 * This will be used as an index for the arrays being created
 * @param in_file ifstream object
**/
int line_counter(std::ifstream& in_file);

void read_file(std::string filename);

void decode_file(std::ifstream& in_file);
void encode_file(std::ifstream& in_file);


#endif