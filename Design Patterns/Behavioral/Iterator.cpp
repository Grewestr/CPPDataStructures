/*****************************************
 * Author: Jordan Grewe
 * Email: gp0569@wayne.edu
 * Date: 2024-05-27
 * 
 * Iterator Pattern
 * 
 * Provides a way to access the elements of an aggregate object sequentially without exposing its underlying representation.
 *****************************************/

#include <iostream>
#include <vector>

// Iterator Interface
template <typename T>
class Iterator {
public:
    virtual bool hasNext() = 0;
    virtual T next() = 0;
};

// Concrete Iterator
template <typename T>
class ConcreteIterator : public Iterator<T> {
private:
    std::vector<T> collection;
    int index;

public:
    ConcreteIterator(const std::vector<T>& collection) : collection(collection), index(0) {}
    bool hasNext() override {
        return index < collection.size();
    }
    T next() override {
        return collection[index++];
    }
};

// Aggregate Interface
template <typename T>
class Aggregate {
public:
    virtual Iterator<T>* createIterator() = 0;
};

// Concrete Aggregate
template <typename T>
class ConcreteAggregate : public Aggregate<T> {
private:
    std::vector<T> collection;

public:
    ConcreteAggregate(const std::vector<T>& collection) : collection(collection) {}
    Iterator<T>* createIterator() override {
        return new ConcreteIterator<T>(collection);
    }
};

// Client code
int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5};
    Aggregate<int>* aggregate = new ConcreteAggregate<int>(numbers);
    Iterator<int>* iterator = aggregate->createIterator();

    while (iterator->hasNext()) {
        std::cout << iterator->next() << " ";
    }
    std::cout << std::endl;

    delete iterator;
    delete aggregate;

    return 0;
}
