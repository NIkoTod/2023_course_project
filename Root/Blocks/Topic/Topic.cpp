//
// Created by nikol on 15.06.2023.
//

#include "Topic.h"


void Topic::writeInFile(std::ofstream &file) const {

}

void Topic::readFromFile(std::ifstream &file) {

}

void Topic::print() const {

    std::cout<<"Title: "<<header.c_str()<<std::endl;
    std::cout<<"Author: "<<authorName.c_str()<<std::endl;
    std::cout<<"Description :"<<std::endl
             <<description.c_str()<<std::endl;

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
}

Block * Topic::clone() const {
    return new Topic(*this);
}

const Collection<Post>& Topic::getPosts() const {
    return postCollection;
}
