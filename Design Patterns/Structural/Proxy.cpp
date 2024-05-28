/*****************************************
 * Author: Jordan Grewe
 * Email: gp0569@wayne.edu
 * Date: 2024-05-27
 * 
 * Proxy Pattern
 * 
 * Provides a surrogate or placeholder for another object to control access to it.
 *****************************************/

#include <iostream>

// Subject Interface
class Subject {
public:
    virtual void request() = 0;
};

// Real Subject
class RealSubject : public Subject {
public:
    void request() override {
        std::cout << "RealSubject request" << std::endl;
    }
};

// Proxy
class Proxy : public Subject {
private:
    RealSubject* realSubject;

public:
    Proxy() : realSubject(nullptr) {}
    ~Proxy() { delete realSubject; }
    void request() override {
        if (realSubject == nullptr) {
            realSubject = new RealSubject();
        }
        realSubject->request();
    }
};

// Client code
int main() {
    Proxy* proxy = new Proxy();
    proxy->request();
    proxy->request();
    delete proxy;

    return 0;
}
