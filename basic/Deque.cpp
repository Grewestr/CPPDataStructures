/*****************************************
 * Author: Jordan Grewe
 * Email: gp0569@wayne.edu
 * Date: 2024-05-27
 *****************************************/

#include <iostream>

class Deque {
private:
    struct Node {
        int data;
        Node* next;
        Node* prev;
    };
    Node* front;
    Node* rear;

public:
    Deque() {
        front = nullptr;
        rear = nullptr;
    }

    // Insert an element at the front of the deque
    void insertFront(int data) {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = front;
        newNode->prev = nullptr;

        if (front == nullptr) {
            rear = newNode;
        } else {
            front->prev = newNode;
        }
        front = newNode;
    }

    // Insert an element at the rear of the deque
    void insertRear(int data) {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = nullptr;
        newNode->prev = rear;

        if (rear == nullptr) {
            front = newNode;
        } else {
            rear->next = newNode;
        }
        rear = newNode;
    }

    // Delete an element from the front of the deque
    void deleteFront() {
        if (isEmpty()) {
            std::cout << "Deque is empty" << std::endl;
            return;
        }

        Node* temp = front;
        front = front->next;

        if (front == nullptr) {
            rear = nullptr;
        } else {
            front->prev = nullptr;
        }
        delete temp;
    }

    // Delete an element from the rear of the deque
    void deleteRear() {
        if (isEmpty()) {
            std::cout << "Deque is empt
