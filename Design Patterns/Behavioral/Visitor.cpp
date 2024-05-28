/*****************************************
 * Author: Jordan Grewe
 * Email: gp0569@wayne.edu
 * Date: 2024-05-27
 * 
 * Visitor Pattern
 * 
 * Represents an operation to be performed on the elements of an object structure, allowing you to define a new operation without changing the classes of the elements on which it operates.
 *****************************************/

#include <iostream>
#include <vector>

// Forward declaration
class ConcreteElementA;
class ConcreteElementB;

// Visitor Interface
class Visitor {
public:
    virtual void visitConcreteElementA(ConcreteElementA* element) = 0;
    virtual void visitConcreteElementB(ConcreteElementB* element) = 0;
};

// Element Interface
class Element {
public:
    virtual void accept(Visitor* visitor) = 0;
};

// Concrete Element A
class ConcreteElementA : public Element {
public:
    void accept(Visitor* visitor) override {
        visitor->visitConcreteElementA(this);
    }
    void operationA() {
        std::cout << "ConcreteElementA operation" << std::endl;
    }
};

// Concrete Element B
class ConcreteElementB : public Element {
public:
    void accept(Visitor* visitor) override {
        visitor->visitConcreteElementB(this);
    }
    void operationB() {
        std::cout << "ConcreteElementB operation" << std::endl;
    }
};

// Concrete Visitor
class ConcreteVisitor : public Visitor {
public:
    void visitConcreteElementA(ConcreteElementA* element) override {
        element->operationA();
    }
    void visitConcreteElementB(ConcreteElementB* element) override {
        element->operationB();
    }
};

// Client code
int main() {
    std::vector<Element*> elements = {new ConcreteElementA(), new ConcreteElementB()};
    Visitor* visitor = new ConcreteVisitor();

    for (Element* element : elements) {
        element->accept(visitor);
    }

    for (Element* element : elements) {
        delete element;
    }
    delete visitor;

    return 0;
}
