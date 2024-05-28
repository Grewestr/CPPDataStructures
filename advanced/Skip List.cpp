/*****************************************
 * Author: Jordan Grewe
 * Email: gp0569@wayne.edu
 * Date: 2024-05-27
 *****************************************/

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>

class Node {
public:
    int value;
    Node** forward;
    Node(int level, int value);
};

Node::Node(int level, int value) {
    this->value = value;
    forward = new Node*[level + 1];
    for (int i = 0; i <= level; i++) {
        forward[i] = nullptr;
    }
}

class SkipList {
private:
    int maxLevel;
    float probability;
    int level;
    Node* header;

    int randomLevel();

public:
    SkipList(int maxLevel, float probability);
    void insert(int value);
    void deleteNode(int value);
    bool search(int value);
    void printList();
};

SkipList::SkipList(int maxLevel, float probability) {
    this->maxLevel = maxLevel;
    this->probability = probability;
    level = 0;
    header = new Node(maxLevel, -1);
}

int SkipList::randomLevel() {
    int lvl = 0;
    while (static_cast<float>(rand()) / RAND_MAX < probability && lvl < maxLevel) {
        lvl++;
    }
    return lvl;
}

void SkipList::insert(int value) {
    Node* current = header;
    Node* update[maxLevel + 1];

    for (int i = level; i >= 0; i--) {
        while (current->forward[i] != nullptr && current->forward[i]->value < value) {
            current = current->forward[i];
        }
        update[i] = current;
    }

    current = current->forward[0];

    if (current == nullptr || current->value != value) {
        int rlevel = randomLevel();

        if (rlevel > level) {
            for (int i = level + 1; i <= rlevel; i++) {
                update[i] = header;
            }
            level = rlevel;
        }

        Node* newNode = new Node(rlevel, value);

        for (int i = 0; i <= rlevel; i++) {
            newNode->forward[i] = update[i]->forward[i];
            update[i]->forward[i] = newNode;
        }
    }
}

void SkipList::deleteNode(int value) {
    Node* current = header;
    Node* update[maxLevel + 1];

    for (int i = level; i >= 0; i--) {
        while (current->forward[i] != nullptr && current->forward[i]->value < value) {
            current = current->forward[i];
        }
        update[i] = current;
    }

    current = current->forward[0];

    if (current != nullptr && current->value == value) {
        for (int i = 0; i <= level; i++) {
            if (update[i]->forward[i] != current) break;
            update[i]->forward[i] = current->forward[i];
        }

        while (level > 0 && header->forward[level] == nullptr) {
            level--;
        }

        delete current;
    }
}

bool SkipList::search(int value) {
    Node* current = header;

    for (int i = level; i >= 0; i--) {
        while (current->forward[i] && current->forward[i]->value < value) {
            current = current->forward[i];
        }
    }

    current = current->forward[0];

    return current && current->value == value;
}

void SkipList::printList() {
    for (int i = 0; i <= level; i++) {
        Node* node = header->forward[i];
        std::cout << "Level " << i << ": ";
        while (node != nullptr) {
            std::cout << node->value << " ";
            node = node->forward[i];
        }
        std::cout << std::endl;
    }
}

int main() {
    srand((unsigned)time(0));

    SkipList lst(3, 0.5);

    lst.insert(3);
    lst.insert(6);
    lst.insert(7);
    lst.insert(9);
    lst.insert(12);
    lst.insert(19);
    lst.insert(17);
    lst.insert(26);
    lst.insert(21);
    lst.insert(25);

    lst.printList();

    std::cout << (lst.search(19) ? "Found 19" : "Not Found 19") << std::endl;
    std::cout << (lst.search(15) ? "Found 15" : "Not Found 15") << std::endl;

    lst.deleteNode(19);
    lst.printList();

    return 0;
}
