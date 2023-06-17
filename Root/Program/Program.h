
#ifndef PROGRAM_H
#define PROGRAM_H

#include "../Factory/CommandFactory.h"
#include "../Interfaces/IProgram.h"

class Program : public IProgram {

    const char* FILE_NAME = "testSaveData.dat";

    Program() = default;
    static Program * program;
    static unsigned currentUserId;
    static Block* currentBlock;

public:

    Program(const Program&) = delete;
    void operator=(const Program&) = delete;

    ~Program() override = default;

    static Program* getInstance();
    void setCurrentUserId(unsigned id) final;
    void setCurrentBlock(Block* block);

    void run();

};

#endif //PROGRAM_H
