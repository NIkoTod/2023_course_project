//
// Created by nikol on 18.06.2023.
//

#ifndef PRINTCOMMENTSCOMMAND_H
#define PRINTCOMMENTSCOMMAND_H

#include "../Command.h"

class CommentListOnPost : public Command{
public:
    bool execute() const override {
        try {

            if(program->getCurrentPost() == nullptr)throw 1;

            program->getCurrentPost()->list();
            return true;
        }catch (int i){
            std::cout<<"You should open some post";
            return false;
        }
        catch (const std::logic_error& e){
            std::cout<<"No comments here";
            return false;
        }
    }

    ~CommentListOnPost() override = default;
};
#endif //PRINTCOMMENTSCOMMAND_H
