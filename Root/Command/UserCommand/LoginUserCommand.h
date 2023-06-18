#ifndef LOGINUSERCOMMAND_H
#define LOGINUSERCOMMAND_H

#include "../../User/User.h"
#include "../Command.h"

class LoginUserCommand : public Command{
public:

    bool execute() const override {

        _string name = Factory::createString("Input first name");
        _string secondName = Factory::createString("Input last name");
        _string password = Factory::createString("Input password");
        User user(name,secondName,password);

        if(repository->containsUser(user)){
            program->setCurrentUserId(repository->getUserId(user));
            return true;
        }
        else return false;
    }
};
#endif //LOGINUSERCOMMAND_H
