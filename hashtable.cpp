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
        this->arr[i]->data = nullptr;
    }
}

void HashTable::insert(const std::string& decode, const std::string& encode) {
    HashNode* newnode = new HashNode;
    newnode->data = encode;
    int pos = hash_code(decode);
    if (arr[pos] != nullptr) {
        newnode->next = arr[pos];
        arr[pos] = newnode;
    }
    else {
        arr[pos] = newnode;
    }
}