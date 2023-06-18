//
// Created by nikol on 18.06.2023.
//

#ifndef TOPICFACTORY_H
#define TOPICFACTORY_H

#include "Factory.h"
#include "../Blocks/Topic/Topic.h"

class TopicFactory: public Factory{
public:

    TopicFactory() = default;
    Topic *create() const override {
        _string header  = createString("Input header");
        _string description = createString("Input description");
        return new Topic(header,description);
    }

    ~TopicFactory() override = default;
};
#endif //TOPICFACTORY_H
