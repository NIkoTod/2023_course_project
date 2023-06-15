#include "_string.h"
_string operator+(const _string& lhs, const _string& rhs)
{
    _string result;  //TBI ??

    return result;
}

_string& _string::operator+=(const _string& other)
{
    char* result = new char[length() + other.length() + 1];
    strcpy(result, _data);
    strcat(result, other._data);

    delete[] _data;
    _data = result;
    size = length() + other.length();

    return *this;
}

_string::_string()
{
    _data = new char[1];
    _data[0] = '\0';
    size = 0;
}
_string::_string(const char* data)
{
    size = strlen(data);
    _data = new char[size + 1];
    strcpy(_data, data);

}

_string::_string(const _string& other)
{
    copyFrom(other);
}

_string& _string::operator=(const _string& other)
{
    if (this != &other)
    {
        free();
        copyFrom(other);
    }
    return *this;
}


void _string::free()
{
    delete[] _data;
    _data = nullptr;
}
_string::~_string()
{
    free();
}

size_t _string::length() const
{
    return size;
}

void _string::copyFrom(const _string& other)
{
    size = other.size;
    _data = new char[size + 1];
    strcpy(_data, other._data);
}

char& _string::operator[](size_t index) //Неконстантен достъп
{
    return _data[index];
}

char _string::operator[](size_t index) const
{
    return _data[index];
}

const char *_string::c_str() const{
    return _data;
}

void _string::moveFrom(_string && other) {

    delete[] _data;
    _data = other._data;
    other._data = nullptr;
    other.size = 0;

}

_string &_string::operator=(_string &&other) noexcept{
    if (this != &other)
    {
        moveFrom(std::move(other));
    }
    return *this;
}
