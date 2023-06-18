//
// Created by nikol on 18.06.2023.
//

#ifndef OPENPOSTCOMMAND_H
#define OPENPOSTCOMMAND_H

#include "../Command.h"

class OpenPostCommand : public Command{
public:
    bool execute() const override {
        try {
            if(program->getCurrentTopic() == nullptr)throw 1;
            unsigned id;
            std::cout << "Input id: ";
            std::cin >> id;
            std::cin.get();
            program->setCurrentPost(program->getCurrentTopic()->getTopicAt(id));
            std::cout<<"Q: "; program->getCurrentPost()->print();
            return true;

        }catch(int i){
            std::cout<<"You should open some topic";
            return false;
        }
        catch(const std::out_of_range& e){
            std::cout<<"No such post";
            return false;
        }
    }

    ~OpenPostCommand() override = default;
};
#endif //OPENPOSTCOMMAND_H
