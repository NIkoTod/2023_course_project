//
// Created by nikol on 18.06.2023.
//

#ifndef COMMENTFACTORY_H
#define COMMENTFACTORY_H

#include "Factory.h"
#include "../Blocks/Comment/Comment.h"

class CommentFactory : public Factory{

public:
    Comment *create() const override {
        return new Comment(createString("Input text"));
    }

    ~CommentFactory() override = default;
};
#endif //COMMENTFACTORY_H
