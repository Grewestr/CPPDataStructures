/*****************************************
 * Author: Jordan Grewe
 * Email: gp0569@wayne.edu
 * Date: 2024-05-27
 *****************************************/

#include <iostream>

// Define a structure for a node in the linked list
struct Node {
    int data;
    Node* next;
};

// Function to print the linked list
void printList(Node* n) {
    while (n != nullptr) {
        std::cout << n->data << " "; // Print the data in each node
        n = n->next; // Move to the next node
    }
}

int main() {
    // Allocate three nodes in the heap
    Node* head = new Node();
    Node* second = new Node();
    Node* third = new Node();

    // Initialize the data and link the nodes
    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = nullptr;

    // Print the linked list
    printList(head);

    // Free allocated memory
    delete head;
    delete second;
    delete third;

    return 0;
}
