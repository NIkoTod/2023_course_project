//
// Created by nikol on 18.06.2023.
//

#ifndef SEARCHTOPICBYHEADER_H
#define SEARCHTOPICBYHEADER_H

#include "../Command.h"
#include "../../Factory/Factory.h"

class SearchTopicByHeader: public Command{
public:

    bool execute() const override {
        try {
            _string toSearch = Factory::createString("");
            repository->printSpecifiedTopics(toSearch);
            return true;
        }catch (...){
            return false;
        }
    }

    ~SearchTopicByHeader() override = default;
};
#endif //SEARCHTOPICBYHEADER_H
