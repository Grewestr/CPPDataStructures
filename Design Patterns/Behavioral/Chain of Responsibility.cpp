/*****************************************
 * Author: Jordan Grewe
 * Email: gp0569@wayne.edu
 * Date: 2024-05-27
 * 
 * Chain of Responsibility Pattern
 * 
 * Passes a request along a chain of handlers, where each handler decides either to handle the request or to pass it to the next handler in the chain.
 *****************************************/

#include <iostream>
#include <string>

// Abstract Handler
class Handler {
protected:
    Handler* next;

public:
    Handler() : next(nullptr) {}
    void setNext(Handler* nextHandler) {
        next = nextHandler;
    }
    virtual void handleRequest(const std::string& request) = 0;
};

// Concrete Handler 1
class ConcreteHandler1 : public Handler {
public:
    void handleRequest(const std::string& request) override {
        if (request == "Handle by Handler1") {
            std::cout << "Handled by Handler1" << std::endl;
        } else if (next) {
            next->handleRequest(request);
        }
    }
};

// Concrete Handler 2
class ConcreteHandler2 : public Handler {
public:
    void handleRequest(const std::string& request) override {
        if (request == "Handle by Handler2") {
            std::cout << "Handled by Handler2" << std::endl;
        } else if (next) {
            next->handleRequest(request);
        }
    }
};

// Client code
int main() {
    Handler* handler1 = new ConcreteHandler1();
    Handler* handler2 = new ConcreteHandler2();

    handler1->setNext(handler2);

    handler1->handleRequest("Handle by Handler1");
    handler1->handleRequest("Handle by Handler2");
    handler1->handleRequest("Unknown Request");

    delete handler1;
    delete handler2;

    return 0;
}
