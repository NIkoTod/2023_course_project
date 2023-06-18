//
// Created by nikol on 18.06.2023.
//

#ifndef PRINTUSERSCOMMAND_H
#define PRINTUSERSCOMMAND_H

#include "../Command.h"

class PrintUsersCommand : public Command{
public:

    bool execute() const override {
        try{

            repository->getUsers().print();
            return true;
        }catch (const std::logic_error& e){
            std::cout<<"No users yet";
            return false;
        }
    }

    ~PrintUsersCommand() override = default;
};
#endif //PRINTUSERSCOMMAND_H
