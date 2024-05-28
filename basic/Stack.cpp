/*****************************************
 * Author: Jordan Grewe
 * Email: gp0569@wayne.edu
 * Date: 2024-05-27
 *****************************************/

#include <iostream>

class Stack {
private:
    struct Node {
        int data;
        Node* next;
    };
    Node* top;

public:
    Stack() {
        top = nullptr;
    }

    // Push an element onto the stack
    void push(int data) {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = top;
        top = newNode;
    }

    // Pop an element from the stack
    void pop() {
        if (isEmpty()) {
            std::cout << "Stack is empty" << std::endl;
            return;
        }
        Node* temp = top;
        top = top->next;
        delete temp;
    }

    // Get the top element of the stack
    int getTop() {
        if (isEmpty()) {
            std::cout << "Stack is empty" << std::endl;
            return -1;
        }
        return top->data;
    }

    // Check if the stack is empty
    bool isEmpty() {
        return top == nullptr;
    }

    // Print the elements of the stack
    void printStack() {
        Node* temp = top;
        while (temp != nullptr) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }

    // Destructor to free memory
    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }
};

int main() {
    Stack s;

    // Push elements onto the stack
    s.push(1);
    s.push(2);
    s.push(3);

    // Print the elements of the stack
    s.printStack(); // Output: 3 2 1

    // Get and print the top element
    std::cout << "Top element: " << s.getTop() << std::endl; // Output: 3

    // Pop an element from the stack
    s.pop();

    // Print the elements of the stack
    s.printStack(); // Output: 2 1

    return 0;
}
