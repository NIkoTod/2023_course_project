//
// Created by nikol on 16.06.2023.
//

#ifndef IWRITEBLE_H
#define IWRITEBLE_H

#include <fstream>

class IWritable{
public:
    virtual void writeInFile(std::ofstream& file) const = 0;
    virtual void readFromFile(std::ifstream& file) = 0;
};
#endif //IWRITEBLE_H
