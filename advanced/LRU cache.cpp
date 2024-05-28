/*****************************************
 * Author: Jordan Grewe
 * Email: gp0569@wayne.edu
 * Date: 2024-05-27
 *****************************************/

#include <iostream>
#include <unordered_map>

class LRUCache {
private:
    struct Node {
        int key, value;
        Node *prev, *next;
        Node(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}
    };

    int capacity;
    std::unordered_map<int, Node*> cache;
    Node *head, *tail;

    void moveToHead(Node* node);
    void removeNode(Node* node);
    void addNode(Node* node);

public:
    LRUCache(int capacity);
    int get(int key);
    void put(int key, int value);
    void display();
};

LRUCache::LRUCache(int capacity) {
    this->capacity = capacity;
    head = new Node(0, 0);
    tail = new Node(0, 0);
    head->next = tail;
    tail->prev = head;
}

void LRUCache::moveToHead(Node* node) {
    removeNode(node);
    addNode(node);
}

void LRUCache::removeNode(Node* node) {
    Node* prev = node->prev;
    Node* next = node->next;
    prev->next = next;
    next->prev = prev;
}

void LRUCache::addNode(Node* node) {
    node->next = head->next;
    node->prev = head;
    head->next->prev = node;
    head->next = node;
}

int LRUCache::get(int key) {
    if (cache.find(key) == cache.end()) {
        return -1;
    }

    Node* node = cache[key];
    moveToHead(node);
    return node->value;
}

void LRUCache::put(int key, int value) {
    if (cache.find(key) != cache.end()) {
        Node* node = cache[key];
        node->value = value;
        moveToHead(node);
    } else {
        Node* node = new Node(key, value);
        cache[key] = node;
        addNode(node);

        if (cache.size() > capacity) {
            Node* tailPrev = tail->prev;
            removeNode(tailPrev);
            cache.erase(tailPrev->key);
            delete tailPrev;
        }
    }
}

void LRUCache::display() {
    Node* node = head->next;
    while (node != tail) {
        std::cout << "(" << node->key << ", " << node->value << ") ";
        node = node->next;
    }
    std::cout << std::endl;
}

int main() {
    LRUCache cache(2);

    cache.put(1, 1);
    cache.put(2, 2);
    cache.display();

    std::cout << "Get 1: " << cache.get(1) << std::endl;
    cache.display();

    cache.put(3, 3);
    cache.display();

    std::cout << "Get 2: " << cache.get(2) << std::endl;
    cache.display();

    cache.put(4, 4);
    cache.display();

    std::cout << "Get 1: " << cache.get(1) << std::endl;
    cache.display();

    std::cout << "Get 3: " << cache.get(3) << std::endl;
    cache.display();

    std::cout << "Get 4: " << cache.get(4) << std::endl;
    cache.display();

    return 0;
}
