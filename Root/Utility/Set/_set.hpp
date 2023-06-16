#ifndef _SET_H
#define _SET_H

#include <iostream>

template<typename T>
class set {

    T* elements;
    size_t size;
    size_t capacity;

    void free();
    void copyFrom(const set<T>& other);
    void resize(size_t newCapacity);



public:

    set();
    set(const set<T>& other);
    ~set();

    void insert(const T& element);
    void remove(const T& element);

    bool contains(const T& element) const;
    size_t getSize() const;
    void print() const;

    set<T>& operator=(const set<T>& other);

};

template<typename T>
set<T> &set<T>::operator=(const set<T> &other) {
    if(this!=&other){
        free();
        copyFrom(other);
    }
    return *this;
}

template<typename T>
set<T>::set(const set<T> &other) {
    copyFrom(other);
}

template<typename T>
void set<T>::copyFrom(const set<T> &other) {

    size = other.size;
    capacity = other.capacity;
    elements = new T[capacity];
    for(int i = 0;i < size;i++){
        elements[i] = other.elements[i];
    }

}

template<typename T>
set<T>::set()
: elements(nullptr), size(0), capacity(0)
{}

template<typename T>
set<T>::~set() {
    free();
}

template<typename T>
void set<T>::insert(const T& element) {

    if (contains(element))
        return;

    if (size == capacity) {
        resize(capacity * 2);
    }

    elements[size++] = element;

}

template<typename T>
void set<T>::remove(const T& element) {

    for (size_t i = 0; i < size; i++) {
        if (elements[i] == element) {
            for (size_t j = i; j < size - 1; j++) {
                elements[j] = elements[j + 1];
            }
            size--;
            return;
        }
    }
}

template<typename T>
bool set<T>::contains(const T& element) const {

    for (size_t i = 0; i < size; i++) {
        if (elements[i] == element)
            return true;
    }
    return false;
}

template<typename T>
size_t set<T>::getSize() const {
    return size;
}

template<typename T>
void set<T>::free() {

    delete[] elements;
    elements = nullptr;
    size = 0;
    capacity = 0;
}

template<typename T>
void set<T>::resize(size_t newCapacity) {

    if(!newCapacity)newCapacity = 2;
    T* newElements = new T[newCapacity];
    for (size_t i = 0; i < size; i++)
        newElements[i] = elements[i];

    capacity = newCapacity;
    delete[] elements;
    elements = newElements;

}


template<typename T>
void set<T>::print() const {

    std::cout << "Set elements: ";
    for (size_t i = 0; i < size; i++) {
        std::cout << elements[i] << " ";
    }
    std::cout << std::endl;
}


#endif //_SET_H
