/*****************************************
 * Author: Jordan Grewe
 * Email: gp0569@wayne.edu
 * Date: 2024-05-27
 *****************************************/

#include <iostream>

// Define a structure for a node in the circular linked list
struct Node {
    int data;
    Node* next;
};

// Function to print the circular linked list
void printList(Node* head) {
    if (head == nullptr) return;
    Node* temp = head;
    do {
        std::cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    std::cout << std::endl;
}

int main() {
    // Allocate three nodes in the heap
    Node* head = new Node();
    Node* second = new Node();
    Node* third = new Node();

    // Initialize the data and link the nodes to form a circular list
    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = head; // Point the last node to the first node to form a circle

    // Print the circular linked list
    printList(head);

    // Free allocated memory
    delete head;
    delete second;
    delete third;

    return 0;
}
