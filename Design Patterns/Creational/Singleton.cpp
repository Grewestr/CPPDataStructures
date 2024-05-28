/*****************************************
 * Author: Jordan Grewe
 * Email: gp0569@wayne.edu
 * Date: 2024-05-27
 * 
 * Singleton Pattern
 * 
 * Ensures a class has only one instance, and provides a global point of access to it.
 *****************************************/

#include <iostream>

class Singleton {
private:
    static Singleton* instance;
    Singleton() {}

public:
    static Singleton* getInstance() {
        if (instance == nullptr) {
            instance = new Singleton();
        }
        return instance;
    }

    void operation() {
        std::cout << "Singleton operation" << std::endl;
    }
};

Singleton* Singleton::instance = nullptr;

int main() {
    Singleton* singleton1 = Singleton::getInstance();
    singleton1->operation();

    Singleton* singleton2 = Singleton::getInstance();
    singleton2->operation();

    // The two instances should be the same
    std::cout << (singleton1 == singleton2 ? "Same instance" : "Different instances") << std::endl;

    return 0;
}
