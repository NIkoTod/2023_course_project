//
// Created by nikol on 18.06.2023.
//

#ifndef INC_2023_COURSE_PROJECT_CLOSEPOSTCOMMAND_H
#define INC_2023_COURSE_PROJECT_CLOSEPOSTCOMMAND_H

#include "../Command.h"

class ClosePostCommand: public Command{
public:
    bool execute() const override {
        program->setCurrentPost(nullptr);
    }

    ~ClosePostCommand() override = default;
};
#endif //INC_2023_COURSE_PROJECT_CLOSEPOSTCOMMAND_H
