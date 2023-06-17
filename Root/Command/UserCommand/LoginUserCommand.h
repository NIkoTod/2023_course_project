#ifndef LOGINUSERCOMMAND_H
#define LOGINUSERCOMMAND_H

#include "../../User/User.h"
#include "../Command.h"

class LoginUserCommand : public Command{
public:

    bool execute() const override {

        _string name = Factory::createString("First name: ");
        _string secondName = Factory::createString("Last name: ");
        _string password = Factory::createString("Password  name: ");
        User user(name,secondName,password);

        if(repository->containsUser(user)){
            program->setCurrentUserId(repository->getUserId(user));
            return true;
        }

        else return false;
    }
};
#endif //LOGINUSERCOMMAND_H
