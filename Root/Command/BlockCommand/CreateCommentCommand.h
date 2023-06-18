//
// Created by nikol on 18.06.2023.
//

#ifndef CREATECOMMENTCOMMAND_H
#define CREATECOMMENTCOMMAND_H

#include "../Command.h"
#include "../../Factory/CommentFactory.h"

class CreateCommentCommand: public Command{
public:
    bool execute() const override {

        try {

            if (program->getCurrentUserId() == -1)throw 1;
            if(program->getCurrentTopic() == nullptr)throw 2;
            if(program->getCurrentPost() == nullptr)throw 3;

            CommentFactory cf;
            Comment * comm = cf.create();
            comm->setId(program->getCurrentPost()->getComments().getSize());
            comm->setAuthor(repository->getUserAt(program->getCurrentUserId()).getName());
            program->getCurrentPost()->addComment(*comm);
            delete comm;
            return true;

        }catch (int i){
            switch (i) {
                case 1:
                    std::cout<<"You are not logged in";
                    break;
                case 2:
                    std::cout<<"You should open some topic";
                    break;
                case 3:
                    std::cout<<"You should open some post";
                    break;
                default:
                    return false;
            }
            return false;
        }

    }

    ~CreateCommentCommand() override = default;
};
#endif //CREATECOMMENTCOMMAND_H
