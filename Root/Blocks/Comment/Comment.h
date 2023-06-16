//
// Created by nikol on 15.06.2023.
//

#ifndef COMMENT_H
#define COMMENT_H


#include "../Block.h"
#include "../../Utility/String/_string.h"
#include "../../Utility/Collection/Collection.hpp"
#include "../../User/User.h"
#include "../../Utility/Set/_set.hpp"


class Comment : public Block{
    _string author;
    _string text;

    Collection<Comment> list;

    set<User> upVotes;
    set<User> downVotes;

    unsigned id;

public:

    Comment() = default;
    Comment(const _string& author, const _string& text);

    void writeInFile(std::ofstream &file) const override;
    void readFromFile(std::ifstream &file) override;

    void print() const override;

    void addFeedBack(const Comment& feedBack);
    void addUpVote(const User& user);
    void addDownVote(const User& user);

    Comment* clone() const override;
    ~Comment() override = default;

};


#endif //COMMENT_H
