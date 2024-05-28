/*****************************************
 * Author: Jordan Grewe
 * Email: gp0569@wayne.edu
 * Date: 2024-05-27
 * 
 * Factory Method Pattern
 * 
 * Defines an interface for creating an object, but lets subclasses alter the type of objects that will be created.
 *****************************************/

#include <iostream>

// Product Interface
class Product {
public:
    virtual void operation() = 0;
};

// Concrete Product 1
class ConcreteProduct1 : public Product {
public:
    void operation() override {
        std::cout << "ConcreteProduct1 operation" << std::endl;
    }
};

// Concrete Product 2
class ConcreteProduct2 : public Product {
public:
    void operation() override {
        std::cout << "ConcreteProduct2 operation" << std::endl;
    }
};

// Creator Interface
class Creator {
public:
    virtual Product* factoryMethod() = 0;
    void someOperation() {
        Product* product = factoryMethod();
        product->operation();
        delete product;
    }
};

// Concrete Creator 1
class ConcreteCreator1 : public Creator {
public:
    Product* factoryMethod() override {
        return new ConcreteProduct1();
    }
};

// Concrete Creator 2
class ConcreteCreator2 : public Creator {
public:
    Product* factoryMethod() override {
        return new ConcreteProduct2();
    }
};

int main() {
    Creator* creator1 = new ConcreteCreator1();
    creator1->someOperation();

    Creator* creator2 = new ConcreteCreator2();
    creator2->someOperation();

    delete creator1;
    delete creator2;

    return 0;
}
