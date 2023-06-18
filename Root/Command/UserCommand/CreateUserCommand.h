#ifndef USERCOMMANDS_H
#define USERCOMMANDS_H

#include "../Command.h"
#include "../../Factory/UserFactory.h"


class CreateUserCommand: public Command{

public:

    bool execute() const override {
        try {

            UserFactory uf;
            User *user = uf.create();
            user->setId(repository->getUsers().getSize());
            repository->addUser(*user);
            delete user;
            return true;
        }
        catch (...) {
            return false;
        }
    }

};
#endif //USERCOMMANDS_H
