#include "_string.h"
_string operator+(const _string& lhs, const _string& rhs)
{
    _string result;
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
    size = 0;
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

char& _string::operator[](size_t index)
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
    size = other.size;
    other.size = 0;

}

_string &_string::operator=(_string &&other) noexcept{
    if (this != &other)
    {
        free();
        moveFrom(std::move(other));
    }
    return *this;
}

bool _string::operator==(const _string &other) {
    return strcmp(_data,other._data) == 0;
}

void _string::writeInFile(std::ofstream &file) const {
    file.write((const char*)&size, sizeof size);
    file.write(_data,size);
}

void _string::readFromFile(std::ifstream &file) {
    file.read((char*) &size,sizeof size);
    _data = new char[size+1];
    file.read(_data,size);
    _data[size] = 0;
}

std::istream &operator>>(std::istream &is,  _string &str) {
    char buff[128];
    is.getline(buff,128);
    str = buff;
    return is;
}
