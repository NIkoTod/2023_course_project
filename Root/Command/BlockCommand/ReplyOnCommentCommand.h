//
// Created by nikol on 18.06.2023.
//

#ifndef REPLYONCOMMENTCOMMAND_H
#define REPLYONCOMMENTCOMMAND_H

#include "../Command.h"
#include "../../Factory/CommentFactory.h"

class ReplyOnCommentCommand: public Command{

public:
    bool execute() const override {
        try {

            if (program->getCurrentUserId() == -1)throw 1;
            if(program->getCurrentTopic() == nullptr)throw 2;
            if(program->getCurrentPost() == nullptr)throw 3;

            unsigned id;
            std::cout << "Input id: ";
            std::cin >> id;
            std::cin.get();
            CommentFactory cf;
            Comment *comm = cf.create();
            comm->setAuthor(repository->getUserAt(program->getCurrentUserId()).getName());
            comm->setId(program->getCurrentPost()->getComments().getSize());
            comm->setText("Reply for "
                    + program->getCurrentPost()->getCommentAt(id)->getAuthor()
                    + ":\n "
                    + comm->getText());

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
        catch(const std::out_of_range& e){
            std::cout<<"No such comment";
            return false;
        }

    }

    ~ReplyOnCommentCommand() override = default;

};
#endif //REPLYONCOMMENTCOMMAND_H
