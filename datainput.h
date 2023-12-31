// Created by Amal Afsal for Encoding lab on 10/28/23.

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

/**
 * Finds the last encoded value in the cipher
 * (ie: apostrophe is last in file and = 10111)
 * Will be used as a reference number to add unknown values to the cipher
*/
int find_last_encoded_value(std::ifstream& in_file);

/**
 * Checks if a char is in the current cipher
 * Will be used to make sure no duplicate values will be in the cipher
*/
bool find_specific_decoded_value(std::string decode);

/**
 * Reads in a txt file from folder directory
 * Calls functions that encodes or decodes based on txt content
 * @param filename the name of txt file
*/
void read_file(std::string filename);

/**
 * Converts encoded text into decoded text
 * @param in_file filestream that holds encoded file
*/
void decode_file(std::ifstream& in_file);
/**
 * Converts decoded text into encoded text
 * @param in_file filestream that holds decoded file
*/
void encode_file(std::ifstream& in_file);


#endif