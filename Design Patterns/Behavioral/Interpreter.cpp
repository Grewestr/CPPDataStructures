/*****************************************
 * Author: Jordan Grewe
 * Email: gp0569@wayne.edu
 * Date: 2024-05-27
 * 
 * Interpreter Pattern
 * 
 * Defines a representation for a language's grammar and uses that representation to interpret sentences in the language.
 *****************************************/

#include <iostream>
#include <string>
#include <vector>
#include <sstream>

// Abstract Expression
class Expression {
public:
    virtual int interpret() = 0;
};

// Terminal Expression for Numbers
class Number : public Expression {
private:
    int number;

public:
    Number(int number) : number(number) {}
    int interpret() override {
        return number;
    }
};

// Non-terminal Expression for Addition
class Add : public Expression {
private:
    Expression* leftExpression;
    Expression* rightExpression;

public:
    Add(Expression* left, Expression* right) : leftExpression(left), rightExpression(right) {}
    int interpret() override {
        return leftExpression->interpret() + rightExpression->interpret();
    }
};

// Non-terminal Expression for Subtraction
class Subtract : public Expression {
private:
    Expression* leftExpression;
    Expression* rightExpression;

public:
    Subtract(Expression* left, Expression* right) : leftExpression(left), rightExpression(right) {}
    int interpret() override {
        return leftExpression->interpret() - rightExpression->interpret();
    }
};

// Client code
Expression* parse(const std::string& token) {
    std::istringstream iss(token);
    std::vector<std::string> tokens((std::istream_iterator<std::string>(iss)),
                                     std::istream_iterator<std::string>());

    Expression* left = new Number(std::stoi(tokens[0]));
    Expression* right = new Number(std::stoi(tokens[2]));
    char op = tokens[1][0];

    switch (op) {
        case '+':
            return new Add(left, right);
        case '-':
            return new Subtract(left, right);
        default:
            return nullptr;
    }
}

int main() {
    std::string expression = "3 + 5";
    Expression* exp = parse(expression);
    std::cout << expression << " = " << exp->interpret() << std::endl;

    delete exp;

    return 0;
}
