//
// Created by nikol on 18.06.2023.
//

#ifndef CREATEPOSTCOMMAND_H
#define CREATEPOSTCOMMAND_H

#include "../Command.h"
#include "../../Factory/PostFactory.h"

class CreatePostCommand: public Command{
public:
    bool execute() const override {

        try {
            if (program->getCurrentUserId() == -1)throw 1;
            if(program->getCurrentTopic() == nullptr)throw 2;
            PostFactory pf;
            Post *post = pf.create();
            post->setId(program->getCurrentTopic()->getPosts().getSize());
            program->getCurrentTopic()->addPost(*post);
            delete post;
            return true;

        }catch (int i){
            switch (i) {
                case 1:
                    std::cout<<"You are not logged in";
                    break;
                case 2:
                    std::cout<<"You should open some topic";
                    break;
                default:
                    return false;
            }
            return false;
        }
    }

    ~CreatePostCommand() override = default;
};
#endif //CREATEPOSTCOMMAND_H
