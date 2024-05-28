/*****************************************
 * Author: Jordan Grewe
 * Email: gp0569@wayne.edu
 * Date: 2024-05-27
 * 
 * Observer Pattern
 * 
 * Defines a one-to-many dependency between objects so that when one object changes state, all its dependents are notified and updated automatically.
 *****************************************/

#include <iostream>
#include <vector>
#include <string>

// Observer Interface
class Observer {
public:
    virtual void update(const std::string& message) = 0;
};

// Subject
class Subject {
private:
    std::vector<Observer*> observers;

public:
    void attach(Observer* observer) {
        observers.push_back(observer);
    }
    void detach(Observer* observer) {
        observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
    }
    void notify(const std::string& message) {
        for (Observer* observer : observers) {
            observer->update(message);
        }
    }
};

// Concrete Observer 1
class ConcreteObserver1 : public Observer {
public:
    void update(const std::string& message) override {
        std::cout << "ConcreteObserver1 received: " << message << std::endl;
    }
};

// Concrete Observer 2
class ConcreteObserver2 : public Observer {
public:
    void update(const std::string& message) override {
        std::cout << "ConcreteObserver2 received: " << message << std::endl;
    }
};

// Client code
int main() {
    Subject* subject = new Subject();

    Observer* observer1 = new ConcreteObserver1();
    Observer* observer2 = new ConcreteObserver2();

    subject->attach(observer1);
    subject->attach(observer2);

    subject->notify("State changed");

    delete observer1;
    delete observer2;
    delete subject;

    return 0;
}
