/*****************************************
 * Author: Jordan Grewe
 * Email: gp0569@wayne.edu
 * Date: 2024-05-27
 *****************************************/

#include <iostream>
#include <list>
#include <vector>

class HashTable {
private:
    int BUCKET; // Number of buckets
    std::vector<std::list<int>> table; // Pointer to an array containing buckets

public:
    HashTable(int V);
    void insertItem(int x);
    void deleteItem(int key);
    int hashFunction(int x) {
        return (x % BUCKET);
    }
    void displayHash();
};

HashTable::HashTable(int b) {
    BUCKET = b;
    table.resize(BUCKET);
}

// Insert a key into the hash table
void HashTable::insertItem(int key) {
    int index = hashFunction(key);
    table[index].push_back(key);
}

// Delete a key from the hash table
void HashTable::deleteItem(int key) {
    int index = hashFunction(key);
    std::list<int>::iterator i;
    for (i = table[index].begin(); i != table[index].end(); i++) {
        if (*i == key)
            break;
    }
    if (i != table[index].end())
        table[index].erase(i);
}

// Display the hash table
void HashTable::displayHash() {
    for (int i = 0; i < BUCKET; i++) {
        std::cout << i;
        for (auto x : table[i])
            std::cout << " --> " << x;
        std::cout << std::endl;
    }
}

int main() {
    int keys[] = {15, 11, 27, 8, 12};
    int n = sizeof(keys) / sizeof(keys[0]);

    HashTable ht(7);

    for (int i = 0; i < n; i++)
        ht.insertItem(keys[i]);

    ht.deleteItem(12);

    ht.displayHash();

    return 0;
}
