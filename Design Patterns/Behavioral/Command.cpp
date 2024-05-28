/*****************************************
 * Author: Jordan Grewe
 * Email: gp0569@wayne.edu
 * Date: 2024-05-27
 * 
 * Command Pattern
 * 
 * Encapsulates a request as an object, thereby allowing parameterization of clients with different requests, queuing of requests, and logging of requests.
 *****************************************/

#include <iostream>
#include <vector>

// Command Interface
class Command {
public:
    virtual void execute() = 0;
};

// Receiver
class Receiver {
public:
    void action() {
        std::cout << "Action performed by Receiver" << std::endl;
    }
};

// Concrete Command
class ConcreteCommand : public Command {
private:
    Receiver* receiver;

public:
    ConcreteCommand(Receiver* r) : receiver(r) {}
    void execute() override {
        receiver->action();
    }
};

// Invoker
class Invoker {
private:
    std::vector<Command*> commands;

public:
    void setCommand(Command* cmd) {
        commands.push_back(cmd);
    }
    void executeCommands() {
        for (Command* cmd : commands) {
            cmd->execute();
        }
    }
};

// Client code
int main() {
    Receiver* receiver = new Receiver();
    Command* command = new ConcreteCommand(receiver);

    Invoker invoker;
    invoker.setCommand(command);
    invoker.executeCommands();

    delete command;
    delete receiver;

    return 0;
}
