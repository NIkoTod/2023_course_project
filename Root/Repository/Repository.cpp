//
// Created by nikol on 16.06.2023.
//

#include "Repository.h"

Repository* Repository::repository = nullptr;

Repository *Repository::GetInstance() {
    if(repository == nullptr)
        repository = new Repository();
    return repository;
}

const Collection<User> &Repository::getUsers() const {
    return users;
}

const Collection<Topic> &Repository::getTopics() const{
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

void Repository::addUser(const User &user) {
    users.add(user);
}

void Repository::addTopic(const Topic &topic) {
    topics.add(topic);
}

Topic &Repository::getTopicAt(unsigned int id) {
    return topics[id];
}

User& Repository::getUserAt(unsigned int id) {
    return users[id];
}

bool Repository::containsUser(const User& user) {
    return users.contains(user);
}

unsigned Repository::getUserId(const User &user) {

    for(int i = 0; i < users.getSize();i++){
        if(users[i] == user)return i;
    }

}
