//
// Created by nikol on 15.06.2023.
//

#ifndef COMMENT_H
#define COMMENT_H


#include "../Block.h"
#include "../../String/_string.h"
#include "../../Collection/Collection.hpp"

class Comment : public Block{
    _string author;
    _string text;

    Collection<Comment> list;

    unsigned id;

public:

    Comment();
    Comment(const _string& author, const _string& text);

    void writeInFile(std::ofstream &file) const override;
    void readFromFile(std::ifstream &file) override;
    void print() const override;
    void addFeedBack(const Comment& feedBack);
    Comment *clone() const override;
    ~Comment() override = default;



};


#endif //COMMENT_H
