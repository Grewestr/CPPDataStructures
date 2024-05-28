/*****************************************
 * Author: Jordan Grewe
 * Email: gp0569@wayne.edu
 * Date: 2024-05-27
 * 
 * Mediator Pattern
 * 
 * Defines an object that encapsulates how a set of objects interact, promoting loose coupling by keeping objects from referring to each other explicitly.
 *****************************************/

#include <iostream>
#include <string>
#include <vector>

// Forward declaration
class Colleague;

// Mediator Interface
class Mediator {
public:
    virtual void send(const std::string& message, Colleague* colleague) = 0;
};

// Colleague Interface
class Colleague {
protected:
    Mediator* mediator;

public:
    Colleague(Mediator* mediator) : mediator(mediator) {}
    virtual void receive(const std::string& message) = 0;
};

// Concrete Colleague 1
class ConcreteColleague1 : public Colleague {
public:
    ConcreteColleague1(Mediator* mediator) : Colleague(mediator) {}
    void send(const std::string& message) {
        mediator->send(message, this);
    }
    void receive(const std::string& message) override {
        std::cout << "Colleague1 received: " << message << std::endl;
    }
};

// Concrete Colleague 2
class ConcreteColleague2 : public Colleague {
public:
    ConcreteColleague2(Mediator* mediator) : Colleague(mediator) {}
    void send(const std::string& message) {
        mediator->send(message, this);
    }
    void receive(const std::string& message) override {
        std::cout << "Colleague2 received: " << message << std::endl;
    }
};

// Concrete Mediator
class ConcreteMediator : public Mediator {
private:
    std::vector<Colleague*> colleagues;

public:
    void addColleague(Colleague* colleague) {
        colleagues.push_back(colleague);
    }
    void send(const std::string& message, Colleague* sender) override {
        for (Colleague* colleague : colleagues) {
            if (colleague != sender) {
                colleague->receive(message);
            }
        }
    }
};

// Client code
int main() {
    ConcreteMediator* mediator = new ConcreteMediator();

    Colleague* colleague1 = new ConcreteColleague1(mediator);
    Colleague* colleague2 = new ConcreteColleague2(mediator);

    mediator->addColleague(colleague1);
    mediator->addColleague(colleague2);

    colleague1->send("Hello from Colleague1");
    colleague2->send("Hello from Colleague2");

    delete colleague1;
    delete colleague2;
    delete mediator;

    return 0;
}
