/*****************************************
 * Author: Jordan Grewe
 * Email: gp0569@wayne.edu
 * Date: 2024-05-27
 * 
 * Memento Pattern
 * 
 * Captures and externalizes an object's internal state so that the object can be restored to this state later, without violating encapsulation.
 *****************************************/

#include <iostream>
#include <string>

// Memento
class Memento {
private:
    std::string state;

public:
    Memento(const std::string& state) : state(state) {}
    std::string getState() const {
        return state;
    }
};

// Originator
class Originator {
private:
    std::string state;

public:
    void setState(const std::string& state) {
        this->state = state;
    }
    std::string getState() const {
        return state;
    }
    Memento* saveStateToMemento() {
        return new Memento(state);
    }
    void getStateFromMemento(Memento* memento) {
        state = memento->getState();
    }
};

// Caretaker
class Caretaker {
private:
    Memento* memento;

public:
    void saveMemento(Memento* memento) {
        this->memento = memento;
    }
    Memento* getMemento() {
        return memento;
    }
};

// Client code
int main() {
    Originator* originator = new Originator();
    Caretaker* caretaker = new Caretaker();

    originator->setState("State1");
    std::cout << "Current State: " << originator->getState() << std::endl;

    caretaker->saveMemento(originator->saveStateToMemento());

    originator->setState("State2");
    std::cout << "Current State: " << originator->getState() << std::endl;

    originator->getStateFromMemento(caretaker->getMemento());
    std::cout << "Restored State: " << originator->getState() << std::endl;

    delete originator;
    delete caretaker;

    return 0;
}
