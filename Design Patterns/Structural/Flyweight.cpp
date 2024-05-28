/*****************************************
 * Author: Jordan Grewe
 * Email: gp0569@wayne.edu
 * Date: 2024-05-27
 * 
 * Flyweight Pattern
 * 
 * Uses sharing to support large numbers of fine-grained objects efficiently.
 *****************************************/

#include <iostream>
#include <unordered_map>
#include <string>

// Flyweight Interface
class Flyweight {
public:
    virtual void operation(const std::string& extrinsicState) = 0;
};

// Concrete Flyweight
class ConcreteFlyweight : public Flyweight {
private:
    std::string intrinsicState;

public:
    ConcreteFlyweight(const std::string& state) : intrinsicState(state) {}
    void operation(const std::string& extrinsicState) override {
        std::cout << "ConcreteFlyweight: " << intrinsicState << ", " << extrinsicState << std::endl;
    }
};

// Flyweight Factory
class FlyweightFactory {
private:
    std::unordered_map<std::string, Flyweight*> flyweights;

public:
    ~FlyweightFactory() {
        for (auto pair : flyweights) {
            delete pair.second;
        }
    }
    Flyweight* getFlyweight(const std::string& key) {
        if (flyweights.find(key) == flyweights.end()) {
            flyweights[key] = new ConcreteFlyweight(key);
        }
        return flyweights[key];
    }
};

// Client code
int main() {
    FlyweightFactory* factory = new FlyweightFactory();

    Flyweight* flyweight1 = factory->getFlyweight("state1");
    flyweight1->operation("extrinsic1");

    Flyweight* flyweight2 = factory->getFlyweight("state2");
    flyweight2->operation("extrinsic2");

    Flyweight* flyweight3 = factory->getFlyweight("state1");
    flyweight3->operation("extrinsic3");

    delete factory;

    return 0;
}
