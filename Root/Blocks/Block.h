//
// Created by nikol on 08.06.2023.
//

#ifndef BLOCK_H
#define BLOCK_H

#include <iostream>
#include "fstream"
#include "../Interfaces/IWriteble.hpp"
#include "../Utility/Collection/Collection.hpp"

class Block : public IWritable{
public:

    virtual void print() const = 0;
    virtual Block* clone() const = 0;
    virtual void list() const {std::cout<<"TBI";}
    virtual ~Block() = default;
};

#endif //BLOCK_H
