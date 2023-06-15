//
// Created by nikol on 15.06.2023.
//

#include "Comment.h"

void Comment::writeInFile(std::ofstream &file) const {

}

void Comment::readFromFile(std::ifstream &file) {

}

void Comment::print() const {
    std::cout<<text.c_str()<<"{id:"<<id<<"}";
}

Comment *Comment::clone() const {
    return new Comment(*this);
}

Comment::Comment() :author(),text(){}

Comment::Comment(const _string &author, const _string &text)
:author(author),text(text){}

void Comment::addFeedBack(const Comment &feedBack) {
    list.add(feedBack);
}
