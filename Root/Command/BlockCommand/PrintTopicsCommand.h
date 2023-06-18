//
// Created by nikol on 18.06.2023.
//

#ifndef PRINTTOPICSCOMMAND_H
#define PRINTTOPICSCOMMAND_H

#include "../Command.h"

class PrintTopicsCommand: public Command{
public:
    bool execute() const override {
       try {
           repository->getTopics().print();
           return true;
       }catch (const std::logic_error& e){
           std::cout<<"No topics here";
           return false;
       }
    }

    ~PrintTopicsCommand() override = default;
};
#endif //PRINTTOPICSCOMMAND_H
