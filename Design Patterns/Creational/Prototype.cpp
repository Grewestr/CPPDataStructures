/*****************************************
 * Author: Jordan Grewe
 * Email: gp0569@wayne.edu
 * Date: 2024-05-27
 * 
 * Prototype Pattern
 * 
 * Specifies the kind of objects to create using a prototypical instance, and creates new objects by copying this prototype.
 *****************************************/

#include <iostream>

// Prototype Interface
class Prototype {
public:
    virtual Prototype* clone() = 0;
    virtual void operation() = 0;
};

// Concrete Prototype 1
class ConcretePrototype1 : public Prototype {
public:
    Prototype* clone() override {
        return new ConcretePrototype1(*this);
    }
    void operation() override {
        std::cout << "ConcretePrototype1 operation" << std::endl;
    }
};

// Concrete Prototype 2
class ConcretePrototype2 : public Prototype {
public:
    Prototype* clone() override {
        return new ConcretePrototype2(*this);
    }
    void operation() override {
        std::cout << "ConcretePrototype2 operation" << std::endl;
    }
};

int main() {
    Prototype* prototype1 = new ConcretePrototype1();
    Prototype* clone1 = prototype1->clone();
    clone1->operation();

    Prototype* prototype2 = new ConcretePrototype2();
    Prototype* clone2 = prototype2->clone();
    clone2->operation();

    delete prototype1;
    delete clone1;
    delete prototype2;
    delete clone2;

    return 0;
}
