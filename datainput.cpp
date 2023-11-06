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
	std::string temp_line; //string that holds a line of text
	std::ifstream in_file;
	in_file.open(filename);
	getline(in_file,temp_line);
	if (temp_line[0] == '0' || temp_line[0] == '1') { //Checks if the text file needs to be decoded or encoded
		in_file.clear(); //Resets error flags on a stream such as EOF
		in_file.seekg(0);//sets position of next character to be read back to beginning of file
		decode_file(in_file); //calls function to decode text
	}
	else {
		in_file.clear(); //Resets error flags on a stream such as EOF
		in_file.seekg(0);//sets position of next character to be read back to beginning of file
		encode_file(in_file); //calls function to encode text
	}
	custom_file(); //Function called to allow user to re-use program/ use a new txt file
}

void decode_file(std::ifstream& in_file) {
	std::string temp_line; //string that stores a line
	std::string temp_encoded; //string that holds the encoded value
	std::string decoded_value = ""; //String that will hold the decoded text

	HashTable* hash = new HashTable; //Creates new hash table
	std::ifstream cipher; 
	cipher.open("cipher-1.txt"); //filestream that holds the cipher
	hash->cipher_input(cipher); //Hashtable takes in data from cipher
	cipher.close(); //filestream closes

	getline(in_file,temp_line); //stors encoded text into temp_line
	std::stringstream ss;
	ss.str(temp_line); //stringstream takes in the temp_line

	while (getline(ss,temp_encoded, ' ')) {
		if (temp_encoded.empty()) { 
			temp_encoded = "-1"; //-1 represents a space in the encoded text
		}
		decoded_value += hash->find_decoded(temp_encoded); //Function returns the converted decoded string
	}

	std::cout << std::endl << "Encoded text: " << temp_line << std::endl; //Displays original encoded text
	std::cout << std::endl << "Decoded text: " << decoded_value << std::endl; //Displays decoded text from encoded text
	std::cout << "Saving to output.txt..." << std::endl; 
	output_data(temp_line, decoded_value); //Program saves encoded and decoded text into a file

	delete hash; //Hash table gets deleted
}

void encode_file(std::ifstream& in_file) {
	std::string temp_line; //string that stores a line
	std::string temp_decoded; //string that holds decoded value
	std::string encoded_value = ""; //string that will hold the encoded text

	BinarySearchTree* tree = new BinarySearchTree; //Creates new binary tree
	std::ifstream cipher;
	cipher.open("cipher-1.txt");
	tree->cipher_input(cipher); //Binarytree takes in data from cipher
	cipher.close();

	getline(in_file,temp_line); //stores decoded text into temp_line
	std::stringstream ss; 
	ss.str(temp_line); //stringstream takes in temp_line
	
	while (getline(ss, temp_decoded, ' ')) { //Grabs string from text file
		for (int i = 0; i < temp_decoded.size(); i++) { //Parses string into individual "string chars"
			std::string char_value(1,temp_decoded[i]);
			tree->find_encoded(encoded_value,char_value); //Binary tree function stores encoded values into string encoded_value
			if (i != temp_decoded.size() - 1) { //Outputs space depending on if last_char or not
            	encoded_value += " "; 
        	}
        	else {
            	encoded_value += "  "; //If reached last char, extra space added
       		}
		}
	}
	std::cout <<std::endl << "Decoded text: " << temp_line << std::endl; //Displays original decoded text
	std::cout << std::endl << "Encoded text: " << encoded_value << std::endl; //Displays encoded text derived from decoded text
	std::cout << "Saving to output.txt..." << std::endl;
	output_data(temp_line, encoded_value); //File saves decoded and encoded text to output.txt

	delete tree; //tree gets deleted
	
}