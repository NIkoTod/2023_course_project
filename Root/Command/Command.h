//
// Created by nikol on 16.06.2023.
//

#ifndef COMMAND_H
#define COMMAND_H

#include "../System/System.h"

class Command{
public:
    virtual bool execute(const System& system) const =0 ;
};
#endif //COMMAND_H
