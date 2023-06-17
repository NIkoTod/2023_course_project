//
// Created by nikol on 17.06.2023.
//

#ifndef COMMANDFACTORY_H
#define COMMANDFACTORY_H

#include "Factory.h"
#include "../Command/UserCommand/CreateUserCommand.h"
#include "../Command/UserCommand/LoginUserCommand.h"

class CommandFactory{
public:
    static Command *create(const _string& association) {
        if(association == "signup") return new CreateUserCommand();
        if(association == "login") return new LoginUserCommand();
        if(association == "logout") return new LoginUserCommand();
        return nullptr;
    }
};
#endif //COMMANDFACTORY_H
