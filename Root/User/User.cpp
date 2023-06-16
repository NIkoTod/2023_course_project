#include "User.h"

User::User(const _string &name, const _string &secondName, const _string &password, unsigned int id)
: name(name), secondName(secondName), password(password), id(id)
{
    points = 0;
}

void User::addPoints(int x) {
    points+=x;
}

const _string &User::getName() const {
    return name;
}

const _string &User::getSecondName() const {
    return secondName;
}

const _string &User::getPassword() const {
    return password;
}

bool User::operator==(const User &other) {
    return name == other.name && secondName == other.secondName;
}

std::ostream &operator<<(std::ostream &os, const User &user) {

    os<<"Name: "<<user.name.c_str()<<std::endl;
    os<<"Second name: "<<user.secondName.c_str()<<std::endl;
    os<<"Points: "<<user.points;
    return os;
}

void User::writeInFile(std::ofstream &file) const {

}

void User::readFromFile(std::ifstream &file) {

}

void User::print() const {
    std::cout<<*this;
}

User *User::clone() const {
    return new User(*this);
}


