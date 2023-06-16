//
// Created by nikol on 16.06.2023.
//

#include "Repository.h"



Repository *Repository::GetInstance() {
    return new Repository();
}

Collection<User> &Repository::getUsersWithFullAccess() {
    return users;
}

Collection<Topic> &Repository::getTopicsWithFullAccess() {
    return topics;
}

bool Repository::writeUsers(std::ofstream &file) const{
        users.writeInFile(file);
}

bool Repository::readUsers(std::ifstream &file) {
    users.readFromFile(file);
}

bool Repository::readData(std::ifstream &file) {
    readUsers(file);
    readTopics(file);
}

bool Repository::saveData(std::ofstream &file) const{
    writeUsers(file);
    writeTopics(file);
}

bool Repository::readTopics(std::ifstream &file) {
    topics.readFromFile(file);

}

bool Repository::writeTopics(std::ofstream &file) const{
    topics.writeInFile(file);

}



