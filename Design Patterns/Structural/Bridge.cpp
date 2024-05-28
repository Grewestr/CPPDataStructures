/*****************************************
 * Author: Jordan Grewe
 * Email: gp0569@wayne.edu
 * Date: 2024-05-27
 * 
 * Adapter Pattern
 * 
 * Converts the interface of a class into another interface clients expect, allowing classes to work together that couldn't otherwise because of incompatible interfaces.
 *****************************************/

#include <iostream>

// Target Interface
class Target {
public:
    virtual void request() = 0;
};

// Adaptee
class Adaptee {
public:
    void specificRequest() {
        std::cout << "Adaptee specific request" << std::endl;
    }
};

// Adapter
class Adapter : public Target {
private:
    Adaptee* adaptee;

public:
    Adapter(Adaptee* adaptee) : adaptee(adaptee) {}
    void request() override {
        adaptee->specificRequest();
    }
};

// Client code
int main() {
    Adaptee* adaptee = new Adaptee();
    Target* target = new Adapter(adaptee);
    target->request();

    delete adaptee;
    delete target;

    return 0;
}
