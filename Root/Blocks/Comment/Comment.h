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

enum class Vote{
    LIKE,
    DISLIKE
};
class Comment : public Block{

    _string author;
    _string text;

    set<User> upVotes;
    set<User> downVotes;

    unsigned id;

public:

    Comment() = default;

    explicit Comment(const _string &text);

    Comment(const _string& author, const _string& text);
    void writeInFile(std::ofstream &file) const override;
    void readFromFile(std::ifstream &file) override;

    void print() const override;


    void setText(const _string &text);

    const _string &getText() const;


    void addVote(const User& user, Vote vote);


    const _string &getAuthor() const;

    void setAuthor(const _string &author);

    unsigned int getId() const;

    void setId(unsigned int id);

    Comment* clone() const override;
    ~Comment() override = default;

};


#endif //COMMENT_H
