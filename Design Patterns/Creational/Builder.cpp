/*****************************************
 * Author: Jordan Grewe
 * Email: gp0569@wayne.edu
 * Date: 2024-05-27
 * 
 * Builder Pattern
 * 
 * Separates the construction of a complex object from its representation, allowing the same construction process to create different representations.
 *****************************************/

#include <iostream>
#include <string>

// Product
class Product {
private:
    std::string partA;
    std::string partB;
    std::string partC;

public:
    void setPartA(const std::string& partA) { this->partA = partA; }
    void setPartB(const std::string& partB) { this->partB = partB; }
    void setPartC(const std::string& partC) { this->partC = partC; }

    void show() {
        std::cout << "Product Parts: " << partA << ", " << partB << ", " << partC << std::endl;
    }
};

// Builder Interface
class Builder {
public:
    virtual void buildPartA() = 0;
    virtual void buildPartB() = 0;
    virtual void buildPartC() = 0;
    virtual Product* getProduct() = 0;
};

// Concrete Builder 1
class ConcreteBuilder1 : public Builder {
private:
    Product* product;

public:
    ConcreteBuilder1() { product = new Product(); }
    void buildPartA() override { product->setPartA("PartA1"); }
    void buildPartB() override { product->setPartB("PartB1"); }
    void buildPartC() override { product->setPartC("PartC1"); }
    Product* getProduct() override { return product; }
};

// Concrete Builder 2
class ConcreteBuilder2 : public Builder {
private:
    Product* product;

public:
    ConcreteBuilder2() { product = new Product(); }
    void buildPartA() override { product->setPartA("PartA2"); }
    void buildPartB() override { product->setPartB("PartB2"); }
    void buildPartC() override { product->setPartC("PartC2"); }
    Product* getProduct() override { return product; }
};

// Director
class Director {
private:
    Builder* builder;

public:
    void setBuilder(Builder* builder) { this->builder = builder; }
    Product* construct() {
        builder->buildPartA();
        builder->buildPartB();
        builder->buildPartC();
        return builder->getProduct();
    }
};

int main() {
    Director director;

    Builder* builder1 = new ConcreteBuilder1();
    director.setBuilder(builder1);
    Product* product1 = director.construct();
    product1->show();

    Builder* builder2 = new ConcreteBuilder2();
    director.setBuilder(builder2);
    Product* product2 = director.construct();
    product2->show();

    delete builder1;
    delete builder2;
    delete product1;
    delete product2;

    return 0;
}
