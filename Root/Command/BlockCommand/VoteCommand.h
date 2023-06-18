//
// Created by nikol on 18.06.2023.
//

#ifndef UPVOTECOMMAND_H
#define UPVOTECOMMAND_H

#include "../Command.h"

class VoteCommand: public Command{
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
            program->getCurrentPost()
                ->getCommentAt(id)
                ->addVote(repository->getUserAt(program->getCurrentUserId()),vote)  ;
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

    ~VoteCommand() override = default;
};
#endif //UPVOTECOMMAND_H
