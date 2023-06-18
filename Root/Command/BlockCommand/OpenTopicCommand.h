//
// Created by nikol on 18.06.2023.
//

#ifndef OPENTOPICCOMMAND_H
#define OPENTOPICCOMMAND_H

#include "../Command.h"

class OpenTopicCommand: public Command{
public:

    bool execute() const override {
        try {

            unsigned id;
            std::cout << "Input id: ";
            std::cin >> id;
            std::cin.get();
            program->setCurrentTopic(repository->getTopicAt(id));
            std::cout<<"Welcome to "<<*program->getCurrentTopic();
            return true;

        }catch(const std::out_of_range& e){
            std::cout<<"No such topic";
            return false;
        }
    }

    ~OpenTopicCommand() override = default;
};
#endif //OPENTOPICCOMMAND_H
