//
// Created by nikol on 15.06.2023.
//

#include "Comment.h"

void Comment::writeInFile(std::ofstream &file) const {

    author.writeInFile(file);
    text.writeInFile(file);
    file.write((const char *) &id,sizeof id);
    upVotes.writeInFile(file);
    downVotes.writeInFile(file);
}

void Comment::readFromFile(std::ifstream &file) {

    author.readFromFile(file);
    text.readFromFile(file);
    file.read((char *)&id,sizeof id);
    upVotes.readFromFile(file);
    downVotes.readFromFile(file);

}

void Comment::print() const {
    std::cout<<std::endl<<"Comment {id:"<<id<<"}"
    << " --- author ("<<author.c_str()<<")"<<"L - "<<upVotes.getSize()
    <<" D - "<<downVotes.getSize()<<std::endl
    <<text.c_str()<<std::endl;

}

Comment *Comment::clone() const {
    return new Comment(*this);
}

Comment::Comment(const _string &author, const _string &text)
:author(author),text(text){}



void Comment::addVote(const User& user,Vote vote) {
    if(Vote::DISLIKE == vote)
        downVotes.insert(user);
    else
        upVotes.insert(user);
}


Comment::Comment(const _string &text)
: text(text) {}

const _string &Comment::getAuthor() const {
    return author;
}

void Comment::setAuthor(const _string &author) {
    Comment::author = author;
}

unsigned int Comment::getId() const {
    return id;
}

void Comment::setId(unsigned int id) {
    Comment::id = id;
}

void Comment::setText(const _string &text) {
    Comment::text = text;
}

const _string &Comment::getText() const {
    return text;
}
