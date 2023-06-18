//
// Created by nikol on 18.06.2023.
//

#ifndef LOGOUTUSERCOMMAND_H
#define LOGOUTUSERCOMMAND_H

#include "../Command.h"

class LogoutUserCommand: public Command{
public:
    bool execute() const override {
        program->setCurrentUserId(-1);
    }

    ~LogoutUserCommand() override = default;
};
#endif //LOGOUTUSERCOMMAND_H
