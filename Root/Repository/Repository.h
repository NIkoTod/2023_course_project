//
// Created by nikol on 16.06.2023.
//

#ifndef SYSTEM_H
#define SYSTEM_H

#include "../Blocks/Topic/Topic.h"

class Repository {

    Collection<User> users;
    Collection<Topic> topics;

    Repository() = default;

    static Repository* singleton_;
    bool readUsers(std::ifstream& file);
    bool writeUsers(std::ofstream& file) const;
    bool readTopics(std::ifstream& file);
    bool writeTopics(std::ofstream& file) const;

public:

    Repository(const Repository &other) = delete;
    void operator=(const Repository &) = delete;
    static Repository *GetInstance();

    Collection<User>& getUsersWithFullAccess();
    Collection<Topic>& getTopicsWithFullAccess();

    bool readData(std::ifstream& file);
    bool saveData(std::ofstream& file) const;

};


#endif //SYSTEM_H
