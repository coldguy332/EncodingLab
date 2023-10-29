#include "datainput.h"

int line_counter(std::ifstream& in_file) {
    //temp string for row of data to be stored in
	std::string temp_line;
	int index = 0; //Index that increments for every row counted

	while (getline(in_file, temp_line)) { //While loop functions until the end of the csv file
		index++; //index number increments
	}

	//Once the end of file is reached, program returns to the top of the page
	//NECESSARY or program will try reading from the bottom of the page when creating country arrays
	in_file.clear(); //Resets error flags on a stream such as EOF
	in_file.seekg(0);//sets position of next character to be read back to beginning of file

	return index; //Returns index number
}

void read_file() {
	std::string temp_line;
	std::ifstream in_file;
	in_file.open("textfile.txt");
	getline(in_file,temp_line);
	if (temp_line[0] == '0' || temp_line[0] == '1') {
		in_file.clear(); //Resets error flags on a stream such as EOF
		in_file.seekg(0);//sets position of next character to be read back to beginning of file

	}
	else {
		in_file.clear(); //Resets error flags on a stream such as EOF
		in_file.seekg(0);//sets position of next character to be read back to beginning of file
		encode_file(in_file);
	}
}

void encode_file(std::ifstream& in_file) {
	std::string temp_line;
	std::string temp_word;
	std::string encoded_value = "";

	HashTable* hash = new HashTable;
	std::ifstream cipher;
	cipher.open("cipher-1.txt");
	hash->cipher_input(cipher);

	getline(in_file,temp_line);
	std::stringstream ss;
	ss.str(temp_line);

	while (getline(ss,temp_word, ' ')) {
		encoded_value += hash->find_encoded(temp_word);
	}
	
	std::cout << std::endl << "Encoded text: " << encoded_value << std::endl;
	std::cout << "Saving to output.txt..." << std::endl;
	output_data(temp_line, encoded_value);
}