//
// Created by nikol on 15.06.2023.
//

#ifndef _STRING_H
#define _STRING_H


#include <iostream>
#include <cstring>
#include "../../Blocks/Block.h"
#include "../Collection/Collection.hpp"
#include <sstream>

class _string: public IWritable
{
    char* _data;
    size_t size;

    void copyFrom(const _string& data);
    void moveFrom(_string&&);
    void free();

public:

    _string();
    _string(const char* data);
    _string(const _string& other);

    size_t length() const;
    const char* c_str() const;

    _string& operator+=(const _string& other);
    _string& operator=(const _string& other);
    _string& operator=(_string&& other) noexcept;
    char& operator[](size_t index);
    char operator[](size_t index) const;
    bool operator==(const _string& other) const;
    bool operator!=(const _string& other)const;

    void writeInFile(std::ofstream &file) const override;
    void readFromFile(std::ifstream &file) override;

    bool containsSubString(const _string& str) const;
    Collection<_string>* split(char delim) const;

    friend std::istream& operator>>(std::istream& is, _string& str);

    ~_string();

};

_string operator+(const _string& lhs, const _string& rhs);


#endif //_STRING_H
