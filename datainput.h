#ifndef DATAINPUT_H
#define DATAINPUT_H

#include <fstream>

/**
 * Function counts how many rows are in the file
 * This will be used as an index for the arrays being created
 * @param in_file ifstream object
**/
int line_counter(std::ifstream& in_file);

#endif