/*****************************************
 * Author: Jordan Grewe
 * Email: gp0569@wayne.edu
 * Date: 2024-05-27
 * 
 * Decorator Pattern
 * 
 * Attaches additional responsibilities to an object dynamically, providing a flexible alternative to subclassing for extending functionality.
 *****************************************/

#include <iostream>

// Component Interface
class Component {
public:
    virtual void operation() = 0;
};

// Concrete Component
class ConcreteComponent : public Component {
public:
    void operation() override {
        std::cout << "ConcreteComponent operation" << std::endl;
    }
};

// Decorator
class Decorator : public Component {
protected:
    Component* component;

public:
    Decorator(Component* component) : component(component) {}
    void operation() override {
        component->operation();
    }
};

// Concrete Decorator A
class ConcreteDecoratorA : public Decorator {
public:
    ConcreteDecoratorA(Component* component) : Decorator(component) {}
    void operation() override {
        Decorator::operation();
        std::cout << "ConcreteDecoratorA operation" << std::endl;
    }
};

// Concrete Decorator B
class ConcreteDecoratorB : public Decorator {
public:
    ConcreteDecoratorB(Component* component) : Decorator(component) {}
    void operation() override {
        Decorator::operation();
        std::cout << "ConcreteDecoratorB operation" << std::endl;
    }
};

// Client code
int main() {
    Component* component = new ConcreteComponent();
    Component* decoratorA = new ConcreteDecoratorA(component);
    Component* decoratorB = new ConcreteDecoratorB(decoratorA);

    decoratorB->operation();

    delete component;
    delete decoratorA;
    delete decoratorB;

    return 0;
}
