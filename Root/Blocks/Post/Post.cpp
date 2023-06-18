#include "Post.h"

void Post::writeInFile(std::ofstream &file) const {
    header.writeInFile(file);
    content.writeInFile(file);
    file.write((const char *)&id,sizeof id);
    comments.writeInFile(file);
}

void Post::readFromFile(std::ifstream &file) {
    header.readFromFile(file);
    content.readFromFile(file);
    file.read(( char *)&id,sizeof id);
    comments.readFromFile(file);
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

Post *Post::clone() const {
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

void Post::setId(unsigned int id) {
    Post::id = id;
}

void Post::list() const {
    try{
        comments.print();
    }catch (const std::logic_error& e){
        std::cout<<"-- No posts here --";
    }catch (...){
        std::cout<<"!! something went wrong !!";
    }
}

const Collection<Comment> &Post::getComments() const {
    return comments;
}

Comment *Post::getCommentAt(unsigned int id) {
    return &comments[id];
}
