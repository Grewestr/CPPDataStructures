/*****************************************
 * Author: Jordan Grewe
 * Email: gp0569@wayne.edu
 * Date: 2024-05-27
 *****************************************/

#include <iostream>

// Define a structure for a node in the doubly linked list
struct Node {
    int data;
    Node* next;
    Node* prev;
};

// Function to print the doubly linked list
void printList(Node* n) {
    Node* last = nullptr;
    std::cout << "Traversal in forward direction: ";
    while (n != nullptr) {
        std::cout << n->data << " ";
        last = n;
        n = n->next;
    }
    std::cout << std::endl;
    std::cout << "Traversal in reverse direction: ";
    while (last != nullptr) {
        std::cout << last->data << " ";
        last = last->prev;
    }
    std::cout << std::endl;
}

int main() {
    // Allocate three nodes in the heap
    Node* head = new Node();
    Node* second = new Node();
    Node* third = new Node();

    // Initialize the data and link the nodes
    head->data = 1;
    head->next = second;
    head->prev = nullptr;

    second->data = 2;
    second->next = third;
    second->prev = head;

    third->data = 3;
    third->next = nullptr;
    third->prev = second;

    // Print the doubly linked list
    printList(head);

    // Free allocated memory
    delete head;
    delete second;
    delete third;

    return 0;
}
