#ifndef POST_H
#define POST_H

#include "../Block.h"
#include "../Comment/Comment.h"


class Post : public Block{

    _string header;
    _string content;
    unsigned id;

    Collection<Comment> comments;

    void copyFrom(const Post& other);
    void moveFrom(Post&& other);

public:

    Post() = default;
    Post(const _string& header,const _string& content);
    Post(const Post& other);
    Post(Post&& other);

    void writeInFile(std::ofstream &file) const override;
    void readFromFile(std::ifstream &file) override;

    void print() const override;
    Block *clone() const override;
    void addComment(const Comment& comment);
    const Collection<Comment>& getComments() const;

    ~Post() override = default;

};

#endif //POST_H