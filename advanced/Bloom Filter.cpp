/*****************************************
 * Author: Jordan Grewe
 * Email: gp0569@wayne.edu
 * Date: 2024-05-27
 *****************************************/

#include <iostream>
#include <vector>
#include <cmath>

class BloomFilter {
private:
    std::vector<bool> bitArray;
    int size;
    int hashCount;

    int hash1(int key) { return key % size; }
    int hash2(int key) { return (key / size) % size; }

public:
    BloomFilter(int size, int hashCount);
    void insert(int key);
    bool contains(int key);
    void display();
};

BloomFilter::BloomFilter(int size, int hashCount) {
    this->size = size;
    this->hashCount = hashCount;
    bitArray.resize(size, false);
}

void BloomFilter::insert(int key) {
    for (int i = 0; i < hashCount; i++) {
        int hashValue = (hash1(key) + i * hash2(key)) % size;
        bitArray[hashValue] = true;
    }
}

bool BloomFilter::contains(int key) {
    for (int i = 0; i < hashCount; i++) {
        int hashValue = (hash1(key) + i * hash2(key)) % size;
        if (!bitArray[hashValue]) {
            return false;
        }
    }
    return true;
}

void BloomFilter::display() {
    for (bool bit : bitArray) {
        std::cout << bit << " ";
    }
    std::cout << std::endl;
}

int main() {
    BloomFilter bf(10, 3);

    bf.insert(23);
    bf.insert(44);
    bf.insert(56);

    bf.display();

    std::cout << (bf.contains(23) ? "23 is in the set" : "23 is not in the set") << std::endl;
    std::cout << (bf.contains(100) ? "100 is in the set" : "100 is not in the set") << std::endl;

    return 0;
}
