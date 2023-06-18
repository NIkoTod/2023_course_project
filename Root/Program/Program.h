
#ifndef PROGRAM_H
#define PROGRAM_H

#include "../Factory/CommandFactory.h"
#include "../Interfaces/IProgram.h"

class Program : public IProgram {

    const char* FILE_NAME = "data.dat";

    Program() = default;
    static Program * program;

public:

    Topic* currentTopic = nullptr;
    Post* currentPost = nullptr;

    unsigned currentUserId = -1;

    Program(const Program&) = delete;
    void operator=(const Program&) = delete;

    ~Program() override = default;

    static Program* getInstance();

    void setCurrentUserId(unsigned id) final;
    unsigned int getCurrentUserId();

    Topic *getCurrentTopic() const override;
    void setCurrentTopic(Topic *currentTopic) override;
    Post *getCurrentPost() const override;
    void setCurrentPost(Post *currentPost) override;


    void readData();
    void saveData();

    void run();

};

#endif //PROGRAM_H
