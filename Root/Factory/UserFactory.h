//
// Created by nikol on 16.06.2023.
//

#ifndef USERFACTORY_H
#define USERFACTORY_H

#include "Factory.h"
#include "../User/User.h"

class UserFactory: Factory{
    static unsigned id;
public:

    UserFactory() = default;
    User* create() const override {
        _string name = createString("Input name");
        _string secondName = createString("Input second name");
        _string password = createString("Input password");
        return new User(name,secondName,password);
    }
};
unsigned UserFactory::id = 0;
#endif //USERFACTORY_H
