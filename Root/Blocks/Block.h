//
// Created by nikol on 08.06.2023.
//

#ifndef BLOCK_H
#define BLOCK_H

#include "fstream"

class Block{
public:

    virtual void writeInFile(std::ofstream& file) const =0;
    virtual void readFromFile(std::ifstream& file) = 0;

    virtual void print() const = 0;
    virtual Block* clone() const = 0;
    virtual ~Block() = default;

};

#endif //BLOCK_H
