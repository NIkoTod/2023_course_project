#ifndef TOPIC_H
#define TOPIC_H


#include "../Block.h"
#include "../Post/Post.h"

class Topic : public Block{

    _string header;
    _string authorName ;
    _string description ;
    unsigned id;

    Collection<Post> postCollection;

    void copyFrom(const Topic& other);


public:

    Topic()  = default;
    Topic(const _string& header,const _string& authorName,const _string& description);
    Topic(const Topic& other);

    Topic(const _string &header, const _string &description);

    ~Topic() = default;

    void addPost(const Post & post);

    void setAuthorName(const _string &authorName);
    void setId(unsigned int id);

    const Collection<Post>& getPosts() const;
    void writeInFile(std::ofstream &file) const override;
    void readFromFile(std::ifstream &file) override;

    Post* getTopicAt(unsigned id);

    const _string &getHeader() const;

    void print() const override;
    void list() const;

    friend std::ostream& operator<<(std::ostream& is, Topic& topic);
    Block* clone() const override;

};


#endif //TOPIC_H
