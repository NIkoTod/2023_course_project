//
// Created by nikol on 15.06.2023.
//

#include "Topic.h"


void Topic::writeInFile(std::ofstream &file) const {

    header.writeInFile(file);
    authorName.writeInFile(file);
    description.writeInFile(file);
    file.write((const char *)&id,sizeof id);
    postCollection.writeInFile(file);

}

void Topic::readFromFile(std::ifstream &file) {

    header.readFromFile(file);
    authorName.readFromFile(file);
    description.readFromFile(file);
    file.read((char *)&id,sizeof id);
    postCollection.readFromFile(file);

}

void Topic::print() const {

    std::cout<<"Title: "<<header.c_str()<<std::endl;
    std::cout<<"Author: "<<authorName.c_str()<<std::endl;
    std::cout<<"Description :"<<description.c_str()<<std::endl;
    std::cout<<"{id:"<<id<<"}";

}

void Topic::addPost(const Post & post) {
    postCollection.add(post);
}

void Topic::list() const {
    try{
        postCollection.print();
    }catch (const std::logic_error& e){
        std::cout<<"-- No posts here --";
    }catch (...){
        std::cout<<"!! something went wrong !!";
    }
}

Topic::Topic(const _string& header,const _string& authorName,const _string& description)
:header(header),authorName(authorName),description(description){

}

Topic::Topic(const Topic &other) {
    copyFrom(other);
}

void Topic::copyFrom(const Topic &other) {
    header = other.header;
    authorName = other.authorName;
    description = other.description;
    id = other.id;
    postCollection = other.postCollection;

}

Block * Topic::clone() const {
    return new Topic(*this);
}

const Collection<Post>& Topic::getPosts() const {
    return postCollection;
}

void Topic::setId(unsigned int id) {
    Topic::id = id;
}

void Topic::setAuthorName(const _string &authorName) {
    Topic::authorName = authorName;
}

const _string &Topic::getHeader() const {
    return header;
}

std::ostream &operator<<(std::ostream &os, Topic &topic) {
    os<<topic.header.c_str()<<" "<<"{id:"<<topic.id<<"}";
    return os;
}

Post *Topic::getTopicAt(unsigned int id) {
    return &postCollection[id];
}

Topic::Topic(const _string &header, const _string &description)
: header(header), description(description) {}
