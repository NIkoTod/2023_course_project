//
// Created by nikol on 18.06.2023.
//

#ifndef INC_2023_COURSE_PROJECT_INFOABOUTTOPICCOMMAND_H
#define INC_2023_COURSE_PROJECT_INFOABOUTTOPICCOMMAND_H

#include "../Command.h"

class InfoAboutTopicCommand : public Command{
public:
    bool execute() const override {
        try {
            unsigned id;
            std::cout << "Input id: ";
            std::cin >> id;
            std::cin.get();
            repository->getTopicAt(id)->print();
            return true;
        } catch(const std::out_of_range& e){
            std::cout<<"No such topic";
            return false;
        }

    }

    ~InfoAboutTopicCommand() override = default;
};
#endif //INC_2023_COURSE_PROJECT_INFOABOUTTOPICCOMMAND_H
