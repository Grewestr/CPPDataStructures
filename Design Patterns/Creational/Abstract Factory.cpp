/*****************************************
 * Author: Jordan Grewe
 * Email: gp0569@wayne.edu
 * Date: 2024-05-27
 * 
 * Abstract Factory Pattern
 * 
 * Provides an interface for creating families of related or dependent objects without specifying their concrete classes.
 *****************************************/

#include <iostream>

// Abstract Product A
class AbstractProductA {
public:
    virtual void operationA() = 0;
};

// Concrete Product A1
class ProductA1 : public AbstractProductA {
public:
    void operationA() override {
        std::cout << "ProductA1 operationA" << std::endl;
    }
};

// Concrete Product A2
class ProductA2 : public AbstractProductA {
public:
    void operationA() override {
        std::cout << "ProductA2 operationA" << std::endl;
    }
};

// Abstract Product B
class AbstractProductB {
public:
    virtual void operationB() = 0;
};

// Concrete Product B1
class ProductB1 : public AbstractProductB {
public:
    void operationB() override {
        std::cout << "ProductB1 operationB" << std::endl;
    }
};

// Concrete Product B2
class ProductB2 : public AbstractProductB {
public:
    void operationB() override {
        std::cout << "ProductB2 operationB" << std::endl;
    }
};

// Abstract Factory
class AbstractFactory {
public:
    virtual AbstractProductA* createProductA() = 0;
    virtual AbstractProductB* createProductB() = 0;
};

// Concrete Factory 1
class ConcreteFactory1 : public AbstractFactory {
public:
    AbstractProductA* createProductA() override {
        return new ProductA1();
    }
    AbstractProductB* createProductB() override {
        return new ProductB1();
    }
};

// Concrete Factory 2
class ConcreteFactory2 : public AbstractFactory {
public:
    AbstractProductA* createProductA() override {
        return new ProductA2();
    }
    AbstractProductB* createProductB() override {
        return new ProductB2();
    }
};

// Client
class Client {
private:
    AbstractProductA* productA;
    AbstractProductB* productB;

public:
    Client(AbstractFactory* factory) {
        productA = factory->createProductA();
        productB = factory->createProductB();
    }
    void run() {
        productA->operationA();
        productB->operationB();
    }
};

int main() {
    AbstractFactory* factory1 = new ConcreteFactory1();
    Client* client1 = new Client(factory1);
    client1->run();

    AbstractFactory* factory2 = new ConcreteFactory2();
    Client* client2 = new Client(factory2);
    client2->run();

    delete client1;
    delete factory1;
    delete client2;
    delete factory2;

    return 0;
}
