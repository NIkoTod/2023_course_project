
#include "Command.h"
#include "../Program/Program.h"

Repository* Command::repository = nullptr;


void Command::setRepository(Repository *repo) {
    Command::repository = repo;
}

void Command::setProgram(IProgram *prog) {
    Command::program = prog;
}
