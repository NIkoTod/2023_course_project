#include "Program.h"

Program* Program::program = nullptr;

Program *Program::getInstance() {
    if(program == nullptr)
        program = new Program();
    return program;
}

void Program::setCurrentUserId(unsigned int id) {
    currentUserId = id;
}


void Program::run() {

    readData();

    Command::setRepository(Repository::GetInstance());
    Command::setProgram(Program::getInstance());
    _string associationOfCommand;

    while(true){

        associationOfCommand = Factory::createString(">> ");
        if(associationOfCommand == "exit") break;

        Command *command = CommandFactory::create(associationOfCommand);

        if(command->execute())
            std::cout<<std::endl<<"Success"<<std::endl;
        else
            std::cout<<std::endl<<"Error!"<<std::endl;

    }

    std::cout<<"Good bye...";

    saveData();

}

void Program::readData() {
    try {
        std::ifstream readFile(FILE_NAME, std::ios::binary);
        if(readFile.is_open()) {
            Repository::GetInstance()->readData(readFile);
            readFile.close();
        }else throw std::logic_error("");
    }catch (const std::logic_error& e) {
        std::cout << "File not found";
    }catch (const std::bad_alloc& e){
        std::cout<<"Data is broken";
        system("exit");
    }
}

void Program::saveData() {
    try {
        std::ofstream writeFile(FILE_NAME,std::ios::binary);
        if(writeFile.is_open()) {
            Repository::GetInstance()->saveData(writeFile);
            writeFile.close();
        }else throw std::logic_error("");
    }catch (const std::logic_error& e){
        std::cout<<"File not found";
    }catch (const std::bad_alloc& e){
        std::cout<<"Data is broken";
        system("exit");
    }
}

unsigned int Program::getCurrentUserId() {
    return currentUserId;
}

Topic *Program::getCurrentTopic() const {
    return currentTopic;
}

void Program::setCurrentTopic(Topic *currentTopic) {
    Program::currentTopic = currentTopic;
}

Post *Program::getCurrentPost() const {
    return currentPost;
}

void Program::setCurrentPost(Post *currentPost) {
    Program::currentPost = currentPost;
}



