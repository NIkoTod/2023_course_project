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

    static Repository* repository;

    bool readUsers(std::ifstream& file);
    bool writeUsers(std::ofstream& file) const;
    bool readTopics(std::ifstream& file);
    bool writeTopics(std::ofstream& file) const;

public:

    Repository(const Repository&) = delete;
    void operator=(const Repository&) = delete;

    static Repository *GetInstance();

    const Collection<User>& getUsers() const;
    const Collection<Topic>& getTopics() const;

    void addUser(const User& user);
    void addTopic(const Topic& topic);

    Topic& getTopicAt(unsigned id);
    User& getUserAt(unsigned id);

    unsigned getUserId(const User& user);
    bool containsUser(const User& user);

    bool readData(std::ifstream& file);
    bool saveData(std::ofstream& file) const;

    ~Repository() = default;

};


#endif //SYSTEM_H
