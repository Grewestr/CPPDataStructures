/*****************************************
 * Author: Jordan Grewe
 * Email: gp0569@wayne.edu
 * Date: 2024-05-27
 * 
 * Composite Pattern
 * 
 * Composes objects into tree structures to represent part-whole hierarchies, allowing clients to treat individual objects and compositions of objects uniformly.
 *****************************************/

#include <iostream>
#include <vector>

// Component Interface
class Component {
public:
    virtual void operation() = 0;
    virtual void add(Component* component) {}
    virtual void remove(Component* component) {}
    virtual Component* getChild(int index) { return nullptr; }
};

// Leaf
class Leaf : public Component {
public:
    void operation() override {
        std::cout << "Leaf operation" << std::endl;
    }
};

// Composite
class Composite : public Component {
private:
    std::vector<Component*> children;

public:
    void operation() override {
        std::cout << "Composite operation" << std::endl;
        for (Component* child : children) {
            child->operation();
        }
    }
    void add(Component* component) override {
        children.push_back(component);
    }
    void remove(Component* component) override {
        children.erase(std::remove(children.begin(), children.end(), component), children.end());
    }
    Component* getChild(int index) override {
        return children[index];
    }
};

// Client code
int main() {
    Component* leaf1 = new Leaf();
    Component* leaf2 = new Leaf();
    Component* composite = new Composite();

    composite->add(leaf1);
    composite->add(leaf2);

    composite->operation();

    delete leaf1;
    delete leaf2;
    delete composite;

    return 0;
}
