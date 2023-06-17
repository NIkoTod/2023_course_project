#ifndef COMMAND_H
#define COMMAND_H


class IProgram;
#include "../Repository/Repository.h"
#include "../Interfaces/IProgram.h"

class Command{
protected:

    static Repository * repository;
    static IProgram * program;

public:

    static void setRepository(Repository * repo);
    static void setProgram(IProgram * prog);
    virtual bool execute() const = 0;

    virtual ~Command() = default;

};



#endif //COMMAND_H
