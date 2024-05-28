/*****************************************
 * Author: Jordan Grewe
 * Email: gp0569@wayne.edu
 * Date: 2024-05-27
 * 
 * State Pattern
 * 
 * Allows an object to alter its behavior when its internal state changes, appearing to change its class.
 *****************************************/

#include <iostream>

// Forward declaration
class Context;

// State Interface
class State {
public:
    virtual void handle(Context* context) = 0;
};

// Context
class Context {
private:
    State* state;

public:
    Context(State* state) : state(state) {}
    void setState(State* state) {
        this->state = state;
    }
    void request();
};

// Concrete State A
class ConcreteStateA : public State {
public:
    void handle(Context* context) override {
        std::cout << "State A" << std::endl;
        context->setState(new ConcreteStateB());
    }
};

// Concrete State B
class ConcreteStateB : public State {
public:
    void handle(Context* context) override {
        std::cout << "State B" << std::endl;
        context->setState(new ConcreteStateA());
    }
};

void Context::request() {
    state->handle(this);
}

// Client code
int main() {
    Context* context = new Context(new ConcreteStateA());
    context->request();
    context->request();
    context->request();

    delete context;

    return 0;
}
