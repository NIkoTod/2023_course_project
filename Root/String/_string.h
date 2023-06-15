//
// Created by nikol on 15.06.2023.
//

#ifndef _STRING_H
#define _STRING_H


#include <iostream>
#include <cstring>
class _string
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
    ~_string();

};

_string operator+(const _string& lhs, const _string& rhs);


#endif //_STRING_H
