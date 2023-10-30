#include "hashtable.h"

/**
 * Ripped from zybooks
 * @https://learn.zybooks.com/zybook/OHLONECS124ChenhansaFall2023/chapter/16/section/5
*/
int hash_code(const std::string& decode) {
   int h = 0;
   for (int i = 0; i < decode.length(); i++)
   {
        h = 31 * h + decode[i];
   }
   if (h < 0) {
        h = h * -1; // Cant have negative index
   }
   h = h % 50; //H must fit in the array given
   return h;
}


HashTable::HashTable() {
    for (int i = 0; i < INDEX; i++) {
        this->arr[i]= nullptr;
    }
}

HashTable::~HashTable() {
    for (int i = 0; i < INDEX; i++) {
        HashNode* current = arr[i];
        while (current != nullptr ) {
            HashNode* del = current;
            current = current->next;
            delete del;
        }
        arr[i] = nullptr;
    }
}

void HashTable::get_data() const {
    for (int i = 0; i < 50; i++) {
        std::cout << i << " ";
        if (arr[i] != nullptr) {
            HashNode* current = arr[i];
            while (current != nullptr) {
                std::cout << current->encoded << " " << current->decoded << " ";
                current = current->next;
            }
        }
        else {
            std::cout << " ";
        }
        std::cout << std::endl;
    }
}


void HashTable::insert(const std::string& decode, const std::string& encode) {
    HashNode* newnode = new HashNode;
    newnode->encoded = encode;
    newnode->decoded = decode;
    int pos = hash_code(encode);
    if (arr[pos] != nullptr) {
        newnode->next = arr[pos];
        arr[pos] = newnode;
    }
    else {
        arr[pos] = newnode;
    }
}

void HashTable::cipher_input(std::ifstream& in_file) {
    int num_of_lines = line_counter(in_file);
    std::string temp_line;
    std::string temp_encode;
    std::string temp_decode;
    for (int i = 0; i < num_of_lines; i++) {
        getline(in_file,temp_line);
        std::stringstream ss;
        ss.str(temp_line);
        getline(ss, temp_decode, '\t');
        getline(ss, temp_encode);

        this->insert(temp_decode,temp_encode);
    }
    in_file.clear(); //Resets error flags on a stream such as EOF
	in_file.seekg(0);//sets position of next character to be read back to beginning of file
}

std::string HashTable::find_decoded(std::string value) {
    std::string return_value = "";
    if (value == "-1") {
        return_value += " ";
    }
    else {
        int pos = hash_code(value);
        HashNode* current = this->arr[pos];
        while (current != nullptr && current->encoded != value) {
            current = current->next;
        }
        return_value += current->decoded;
    }
    return return_value; 
}