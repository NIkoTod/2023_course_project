
#include "Command.h"


Repository* Command::repository = nullptr;
IProgram* Command::program = nullptr;
Vote Command::vote = Vote::LIKE;

void Command::setRepository(Repository *repo) {
    Command::repository = repo;
}

void Command::setProgram(IProgram *prog) {
    Command::program = prog;
}

Command* Command::provideVoteType(Vote vote){
    Command::vote = vote;
    return this;
}