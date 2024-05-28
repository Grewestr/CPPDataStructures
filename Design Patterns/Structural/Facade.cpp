/*****************************************
 * Author: Jordan Grewe
 * Email: gp0569@wayne.edu
 * Date: 2024-05-27
 * 
 * Facade Pattern
 * 
 * Provides a unified interface to a set of interfaces in a subsystem, making the subsystem easier to use.
 *****************************************/

#include <iostream>

// Subsystem 1
class Subsystem1 {
public:
    void operation1() {
        std::cout << "Subsystem1 operation1" << std::endl;
    }
};

// Subsystem 2
class Subsystem2 {
public:
    void operation2() {
        std::cout << "Subsystem2 operation2" << std::endl;
    }
};

// Facade
class Facade {
private:
    Subsystem1* subsystem1;
    Subsystem2* subsystem2;

public:
    Facade() {
        subsystem1 = new Subsystem1();
        subsystem2 = new Subsystem2();
    }
    ~Facade() {
        delete subsystem1;
        delete subsystem2;
    }
    void operation() {
        subsystem1->operation1();
        subsystem2->operation2();
    }
};

// Client code
int main() {
    Facade* facade = new Facade();
    facade->operation();
    delete facade;

    return 0;
}
