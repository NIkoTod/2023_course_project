//
// Created by nikol on 18.06.2023.
//

#ifndef INC_2023_COURSE_PROJECT_IPROGRAM_H
#define INC_2023_COURSE_PROJECT_IPROGRAM_H
class IProgram{
public:
    virtual void setCurrentUserId(unsigned id) = 0;
    virtual ~IProgram() = default;
};
#endif //INC_2023_COURSE_PROJECT_IPROGRAM_H
