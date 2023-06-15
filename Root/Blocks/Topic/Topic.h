#ifndef TOPIC_H
#define TOPIC_H


#include "../Block.h"
#include "../Post/Post.h"
#include "../../String/_string.h"
#include "../../Collection/Collection.hpp"


class Topic : public Block{

    _string header;
    _string authorName ;
    _string description ;
    unsigned id;

    Collection<Post> postCollection;

    void copyFrom(const Topic& other);


public:

    Topic();
    Topic(const _string& header,const _string& authorName,const _string& description);
    Topic(const Topic& other);
    ~Topic() = default;

    void addPost(const Post & post);
    Collection<Post>& getPosts();
    void writeInFile(std::ofstream &file) const override;
    void readFromFile(std::ifstream &file) override;
    void print() const override;
    void list() const;

    Block* clone() const override;

};


#endif //TOPIC_H
