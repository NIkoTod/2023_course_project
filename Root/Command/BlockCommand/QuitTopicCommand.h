//
// Created by nikol on 18.06.2023.
//

#ifndef QUITTOPICCOMMAND_H
#define QUITTOPICCOMMAND_H

#include "../Command.h"

class QuitTopicCommand: public Command{
public:
    bool execute() const override {
        program->setCurrentTopic(nullptr);
        program->setCurrentPost(nullptr);
    }

    ~QuitTopicCommand() override = default;
};
#endif //QUITTOPICCOMMAND_H
