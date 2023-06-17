#include "Program.h"

Program* Program::program = nullptr;
unsigned Program::currentUserId = 0;
Block* Program::currentBlock = nullptr;

Program *Program::getInstance() {
    if(program == nullptr)
        program = new Program();
    return program;
}

void Program::setCurrentUserId(unsigned int id) {
    currentUserId = id;
}

void Program::setCurrentBlock(Block *block) {
    currentBlock = block;
}

void Program::run() {

    std::ifstream readFile(FILE_NAME,std::ios::binary);
    Repository::GetInstance()->readData(readFile);
    readFile.close();

    Command::setRepository(Repository::GetInstance());
    Command::setProgram(Program::getInstance());
    _string associationOfCommand;

    while(associationOfCommand != "quit"){
        associationOfCommand = Factory::createString(">> ");
        Command *command = CommandFactory::create(associationOfCommand);

        if(command->execute())
            std::cout<<"Success";
        else
            std::cout<<"Error!";
    }

    std::cout<<"Good bye...";

    std::ofstream writeFile(FILE_NAME,std::ios::binary);
    Repository::GetInstance()->saveData(writeFile);
    writeFile.close();

}
