//
// Created by nikol on 16.06.2023.
//

#ifndef FACTORY_H
#define FACTORY_H

#include "../Blocks/Block.h"
#include "../Utility/String/_string.h"

class Factory{
public:

    Factory() = default;

    virtual Block& create() const {}

    static _string createString(const char* message){
        std::cout<<message<<": "<<std::endl;
        _string str;
        std::cin >> str;
        return str;
    }

};
#endif //FACTORY_H
