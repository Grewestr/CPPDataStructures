/*****************************************
 * Author: Jordan Grewe
 * Email: gp0569@wayne.edu
 * Date: 2024-05-27
 * 
 * Template Method Pattern
 * 
 * Defines the skeleton of an algorithm in a method, deferring some steps to subclasses, allowing subclasses to redefine certain steps of an algorithm without changing its structure.
 *****************************************/

#include <iostream>

// Abstract Class
class AbstractClass {
public:
    void templateMethod() {
        step1();
        step2();
        step3();
    }

protected:
    virtual void step1() = 0;
    virtual void step2() = 0;
    virtual void step3() = 0;
};

// Concrete Class 1
class ConcreteClass1 : public AbstractClass {
protected:
    void step1() override {
        std::cout << "ConcreteClass1 step1" << std::endl;
    }
    void step2() override {
        std::cout << "ConcreteClass1 step2" << std::endl;
    }
    void step3() override {
        std::cout << "ConcreteClass1 step3" << std::endl;
    }
};

// Concrete Class 2
class ConcreteClass2 : public AbstractClass {
protected:
    void step1() override {
        std::cout << "ConcreteClass2 step1" << std::endl;
    }
    void step2() override {
        std::cout << "ConcreteClass2 step2" << std::endl;
    }
    void step3() override {
        std::cout << "ConcreteClass2 step3" << std::endl;
    }
};

// Client code
int main() {
    AbstractClass* class1 = new ConcreteClass1();
    class1->templateMethod();

    AbstractClass* class2 = new ConcreteClass2();
    class2->templateMethod();

    delete class1;
    delete class2;

    return 0;
}
