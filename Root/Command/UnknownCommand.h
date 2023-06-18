//
// Created by nikol on 18.06.2023.
//

#ifndef UNKNOWNCOMMAND_H
#define UNKNOWNCOMMAND_H

#include "Command.h"

class UnknownCommand: public Command{
public:
    bool execute() const override {
        std::cout<<"Unknown Command!";
        return false;
    }

    ~UnknownCommand() override = default;
};
#endif //UNKNOWNCOMMAND_H
