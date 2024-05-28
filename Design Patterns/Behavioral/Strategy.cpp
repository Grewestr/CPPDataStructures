/*****************************************
 * Author: Jordan Grewe
 * Email: gp0569@wayne.edu
 * Date: 2024-05-27
 * 
 * Strategy Pattern
 * 
 * Defines a family of algorithms, encapsulates each one, and makes them interchangeable, allowing the algorithm to vary independently from clients that use it.
 *****************************************/

#include <iostream>

// Strategy Interface
class Strategy {
public:
    virtual void execute() = 0;
};

// Concrete Strategy 1
class ConcreteStrategy1 : public Strategy {
public:
    void execute() override {
        std::cout << "Executing Strategy 1" << std::endl;
    }
};

// Concrete Strategy 2
class ConcreteStrategy2 : public Strategy {
public:
    void execute() override {
        std::cout << "Executing Strategy 2" << std::endl;
    }
};

// Context
class Context {
private:
    Strategy* strategy;

public:
    void setStrategy(Strategy* strategy) {
        this->strategy = strategy;
    }
    void executeStrategy() {
        strategy->execute();
    }
};

// Client code
int main() {
    Context* context = new Context();

    Strategy* strategy1 = new ConcreteStrategy1();
    context->setStrategy(strategy1);
    context->executeStrategy();

    Strategy* strategy2 = new ConcreteStrategy2();
    context->setStrategy(strategy2);
    context->executeStrategy();

    delete strategy1;
    delete strategy2;
    delete context;

    return 0;
}
