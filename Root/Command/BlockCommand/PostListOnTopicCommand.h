//
// Created by nikol on 18.06.2023.
//

#ifndef POSTLISTONTOPICCOMMAND_H
#define POSTLISTONTOPICCOMMAND_H

#include "../Command.h"

class PostListOnTopicCommand: public Command{

public:

    bool execute() const override {
        try {
            program->getCurrentTopic()->list();
            return true;
        }catch (const std::logic_error& e){
            std::cout<<"No posts here";
            return false;
        }
    }

    ~PostListOnTopicCommand() override = default;

};
#endif //POSTLISTONTOPICCOMMAND_H
