//
// Created by nikol on 16.06.2023.
//

#ifndef USER_H
#define USER_H


#include "../Utility/String/_string.h"
#include "../Blocks/Block.h"

class User: public Block {

    _string name;
    _string secondName;
    _string password;
    unsigned id;
    int points;

public:

    User() = default;
    User(const _string &name, const _string &secondName, const _string &password, unsigned int id);
    ~User() = default;

    void addPoints(int x);

    const _string& getName() const;
    const _string& getSecondName() const;
    const _string& getPassword() const;

    void writeInFile(std::ofstream &file) const override;
    void readFromFile(std::ifstream &file) override;

    void print() const override;
    User *clone() const override;

    bool operator==(const User& other);
    friend std::ostream& operator<<(std::ostream& os,const User& user);

};


#endif //USER_H
