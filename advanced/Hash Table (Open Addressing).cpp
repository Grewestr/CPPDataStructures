/*****************************************
 * Author: Jordan Grewe
 * Email: gp0569@wayne.edu
 * Date: 2024-05-27
 *****************************************/

#include <iostream>

class HashTable {
private:
    int *table;
    int size;
    int currentSize;

public:
    HashTable(int size);
    bool isFull() { return (currentSize == size); }
    int hashFunction(int key) { return key % size; }
    void insertItem(int key);
    void deleteItem(int key);
    void displayHash();
};

HashTable::HashTable(int s) {
    size = s;
    table = new int[size];
    currentSize = 0;
    for (int i = 0; i < size; i++)
        table[i] = -1; // Initialize all elements to -1
}

// Insert a key into the hash table
void HashTable::insertItem(int key) {
    if (isFull())
        return;

    int index = hashFunction(key);

    while (table[index] != -1) {
        index = (index + 1) % size;
    }

    table[index] = key;
    currentSize++;
}

// Delete a key from the hash table
void HashTable::deleteItem(int key) {
    int index = hashFunction(key);

    while (table[index] != -1) {
        if (table[index] == key) {
            table[index] = -1;
            currentSize--;
            return;
        }
        index = (index + 1) % size;
    }
}

// Display the hash table
void HashTable::displayHash() {
    for (int i = 0; i < size; i++) {
        if (table[i] != -1)
            std::cout << i << " --> " << table[i] << std::endl;
        else
            std::cout << i << std::endl;
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
