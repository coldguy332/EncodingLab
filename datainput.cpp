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

void read_file(std::string filename) {
	std::string temp_line;
	std::ifstream in_file;
	in_file.open(filename);
	getline(in_file,temp_line);
	if (temp_line[0] == '0' || temp_line[0] == '1') {
		in_file.clear(); //Resets error flags on a stream such as EOF
		in_file.seekg(0);//sets position of next character to be read back to beginning of file
		decode_file(in_file);

	}
	else {
		in_file.clear(); //Resets error flags on a stream such as EOF
		in_file.seekg(0);//sets position of next character to be read back to beginning of file
		encode_file(in_file);
	}
	custom_file();
}

void decode_file(std::ifstream& in_file) {
	std::string temp_line;
	std::string temp_encoded;
	std::string decoded_value = "";

	HashTable* hash = new HashTable;
	std::ifstream cipher;
	cipher.open("cipher-1.txt");
	hash->cipher_input(cipher);
	cipher.close();

	getline(in_file,temp_line);
	std::stringstream ss;
	ss.str(temp_line);

	while (getline(ss,temp_encoded, ' ')) {
		if (temp_encoded.empty()) {
			temp_encoded = "-1";
		}
		decoded_value += hash->find_decoded(temp_encoded);
	}
	
	std::cout << std::endl << "Decoded text: " << decoded_value << std::endl;
	std::cout << "Saving to output.txt..." << std::endl;
	output_data(temp_line, decoded_value);

	delete hash;
}

void encode_file(std::ifstream& in_file) {
	std::string temp_line;
	std::string temp_decoded;
	std::string encoded_value = "";

	BinarySearchTree* tree = new BinarySearchTree;
	std::ifstream cipher;
	cipher.open("cipher-1.txt");
	tree->cipher_input(cipher);
	cipher.close();

	getline(in_file,temp_line);
	std::stringstream ss;
	ss.str(temp_line);
	
	while (getline(ss, temp_decoded, ' ')) { //Grabs string from text file
		for (int i = 0; i < temp_decoded.size(); i++) { //Parses string into individual "string chars"
			std::string char_value(1,temp_decoded[i]);
			tree->find_encoded(encoded_value,char_value); //Binary tree function returns an encoded value
			if (i != temp_decoded.size() - 1) { //Outputs space depending on if string is at last char or not
            	encoded_value += " "; 
        	}
        	else {
            	encoded_value += "  ";
       		}
		}
	}
	std::cout << std::endl << "Encoded text: " << encoded_value << std::endl;
	std::cout << "Saving to output.txt..." << std::endl;
	output_data(temp_line, encoded_value);

	delete tree;
	
}