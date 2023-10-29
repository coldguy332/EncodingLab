#include "savedata.h"

void output_data(std::string a, std::string b) {
    std::ofstream out_file;
    out_file.open("output.txt");
    out_file << a << std::endl << std::endl << b;
}