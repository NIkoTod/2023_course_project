//
// Created by nikol on 16.06.2023.
//

#ifndef USERCOMMANDS_H
#define USERCOMMANDS_H

#include "../Command.h"
#include "../../User/User.h"
#include "../../Utility/Collection/Collection.hpp"

class CreateUserCommand: public Command{

public:

    bool execute(const System& system) const override {

    }

    void readUsers(){

    }

};
#endif //USERCOMMANDS_H
