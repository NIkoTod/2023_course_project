#ifndef COMMAND_H
#define COMMAND_H


class IProgram;
#include "../Repository/Repository.h"
#include "../Interfaces/IProgram.h"

class Command{
protected:

    static Repository * repository;
    static IProgram * program;
    static Vote vote;

public:

    static void setRepository(Repository * repo);
    static void setProgram(IProgram * prog);

    virtual bool execute() const = 0;
    Command *provideVoteType(Vote vote);
    virtual ~Command() = default;

};



#endif //COMMAND_H
