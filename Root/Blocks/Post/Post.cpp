#include "Post.h"

void Post::writeInFile(std::ofstream &file) const {

}

void Post::readFromFile(std::ifstream &file) {

}

void Post::print() const {
    std::cout<<header.c_str()<<" {id:"<<id<<"}";
}



void Post::addComment(const Comment &comment) {
    comments.add(comment);
}

Post::Post(const _string &header, const _string &content)
:header(header),content(content)
{
}

Block *Post::clone() const {
    return new Post(*this);
}

void Post::copyFrom(const Post &other) {

    header = other.header;
    content = other.content;
    id = other.id;
    comments = other.comments;

}

void Post::moveFrom(Post &&other) {
    header = std::move(other.header);
    content = std::move(other.content);
    comments = std::move(other.comments);
    id = other.id;
    other.id = 0;
}


Post::Post(const Post &other) {
    copyFrom(other);
}

Post::Post(Post &&other):header(),content() {
    moveFrom(std::move(other));
}

const Collection<Comment> &Post::getComments() const{
    return comments;
}
