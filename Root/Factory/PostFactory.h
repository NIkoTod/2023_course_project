//
// Created by nikol on 18.06.2023.
//

#ifndef POSTFACTORY_H
#define POSTFACTORY_H

#include "Factory.h"
#include "../Blocks/Post/Post.h"

class PostFactory: public Factory{
public:
    Post *create() const override {

        _string header = createString("Input header");
        _string content = createString("Input content");
        return new Post(header,content);

    }

    ~PostFactory() override = default;
};

#endif //POSTFACTORY_H
