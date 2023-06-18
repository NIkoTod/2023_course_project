//
// Created by nikol on 18.06.2023.
//

#ifndef CREATETOPICCOMMAND_H
#define CREATETOPICCOMMAND_H

#include "../Command.h"
#include "../../Factory/TopicFactory.h"

class CreateTopicCommand: public Command{
public:
    bool execute() const override {
        try {
            if (program->getCurrentUserId() == -1)throw std::logic_error("no actual user");

            TopicFactory tf;
            Topic *topic = tf.create();
            topic->setId(repository->getTopics().getSize());
            topic->setAuthorName(repository->getUserAt(program->getCurrentUserId()).getName());
            repository->addTopic(*topic);
            delete topic;
            return true;
        }catch (const std::logic_error& e){
            std::cout<<"You are not logged in";
            return false;
        }
        catch(...){
            return false;
        }
    }

    ~CreateTopicCommand() override = default;
};
#endif //INC_2023_COURSE_PROJECT_CREATETOPICCOMMAND_H
