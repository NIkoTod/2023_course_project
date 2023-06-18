//
// Created by nikol on 18.06.2023.
//

#ifndef PRINTPROFILECOMMAND_H
#define PRINTPROFILECOMMAND_H

#include "../Command.h"

class PrintProfileCommand: public Command{
public:
    bool execute() const override {
        if(program->getCurrentUserId() != -1) {
            repository->getUserAt(program->getCurrentUserId()).print();
        }else
            std::cout<<"Quest";

    }

    ~PrintProfileCommand() override = default;
};
#endif //PRINTPROFILECOMMAND_H
