#include "hashtable.h"


int hash_code(const std::string& decode) {
   int h = 0;
   for (int i = 0; i < decode.length(); i++)
   {
        h = 31 * h + decode[i];
   }
   if (h < 0) {
        h = h * -1; // To ensure all positive numbers, can't have negative index
   }
   h = h % 50; //H must fit in the array given (we're using default value of 50)
   return h;
}


HashTable::HashTable() {
    for (int i = 0; i < INDEX; i++) {
        this->arr[i]= nullptr; //sets all ptrs initially to null
    }
}

HashTable::~HashTable() {
    for (int i = 0; i < INDEX; i++) { //Must traverse through all 50 array positions
        HashNode* current = arr[i]; //sets pointer to the current array position
        while (current != nullptr ) { //checks if the array position is null
            HashNode* del = current; //node to be deleted set to current ptr
            current = current->next; //current ptr sets itself to its next ptr
            delete del; //old current becomes deleted
        }
        arr[i] = nullptr; //ptr at array position i set to null
    }
}



void HashTable::insert(const std::string& decode, const std::string& encode) {
    HashNode* newnode = new HashNode; //new node gets created
    newnode->encoded = encode; //newnode stores encoded string
    newnode->decoded = decode; //newnode stores decoded string
    int pos = hash_code(encode); //array position found by the encoded string
    if (arr[pos] != nullptr) { //checks if a node exists (a collision)
        newnode->next = arr[pos]; 
        arr[pos] = newnode; //newnode becomes head of SLL
    }
    else { //else newnode becomes the head at that array position
        arr[pos] = newnode;
    }
}

void HashTable::cipher_input(std::ifstream& in_file) {
    int num_of_lines = line_counter(in_file); //Counts number of lines in cipher
    std::string temp_line; //will store the line in txt file
    std::string temp_encode; //Will store an encoded value (ex: "0010")
    std::string temp_decode; //Will store a decoded value (ex: 'A')
    for (int i = 0; i < num_of_lines; i++) { //Loop that cycles until the end of file
        getline(in_file,temp_line); //stores lines into the temp line
        std::stringstream ss; //stringstream necessary to parse the line
        ss.str(temp_line);  //stringstream takes in the value of the templine
        getline(ss, temp_decode, '\t'); //stores decoded value into temp_decode
        getline(ss, temp_encode); //stores encoded value into temp_encode

        this->insert(temp_decode,temp_encode); //Creates newnode with this data and inserts into hash table
    }
    in_file.clear(); //Resets error flags on a stream such as EOF
	in_file.seekg(0);//sets position of next character to be read back to beginning of file
}

std::string HashTable::find_decoded(std::string encoded_value) {
    std::string return_value = ""; //string to be returned
    if (encoded_value == "-1") { //-1 signifies space
        return_value += " "; //return value just adds a space
    }
    else {
        int pos = hash_code(encoded_value); //finds the array position of the string passed through
        HashNode* current = this->arr[pos]; //ptr set to the array position
        while (current != nullptr && current->encoded != encoded_value) { 
            current = current->next; //current traverses until the appropriate node is found
        }
        if (current == nullptr) { //If no encoded value can be found in the hash table
            std::cout << std::endl << "WARNING: Unrecognized value: " << encoded_value << std::endl;
            return_value += "?"; //Question mark will represent an unknown
        }
        else {
            return_value += current->decoded;  //return value takes in the appropriate decoded value
        }
    }
    return return_value; //decoded value gets returned
}