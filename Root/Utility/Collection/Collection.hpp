//
// Created by nikol on 15.06.2023.
//

#ifndef COLLECTION_H
#define COLLECTION_H

#include <iostream>

template<class T>
class Collection : IWritable{

    T** list;
    size_t capacity;
    size_t size;

    void copyFrom(const Collection& other);
    void moveFrom(Collection&& other);

    void free();
    void resize(int newCapacity);

public:

    Collection();
    Collection(const Collection<T>& other);
    Collection(Collection<T>&& other) noexcept;
    ~Collection();


public:

    void writeInFile(std::ofstream &file) const override;
    void readFromFile(std::ifstream &file) override ;

    void add(const T& el);
    void add(T&& el);
    void print() const;
    bool isEmpty() const;

    size_t getSize() const;

    T& operator[](unsigned x);
    T& operator[](unsigned x) const;

    Collection<T>& operator=(const Collection &other);
    Collection<T>& operator=(Collection &&other) noexcept;

};

template<class T>
void Collection<T>::add(T &&el) {

    if(size == capacity){
        resize(capacity*2);
    }
    *list[size++] = std::move(el);

}

template<class T>
void Collection<T>::readFromFile(std::ifstream &file) {
    file.read((char *) &size,sizeof size);
    file.read((char *) &capacity,sizeof capacity);
    for(int i = 0 ; i < size;i++){
        list[i]->readFromFile(file);
    }
}

template<class T>
void Collection<T>::writeInFile(std::ofstream &file) const {
    file.write((const char *) &size,sizeof size);
    file.write((const char *) &capacity,sizeof capacity);
    for(int i = 0 ; i < size;i++){
        list[i]->writeInFile(file);
    }
}

template<class T>
size_t Collection<T>::getSize() const {
    return size;
}

template<class T>
bool Collection<T>::isEmpty() const{
    return size == 0;
}

template<class T>
Collection<T> &Collection<T>::operator=(Collection &&other) noexcept {

    if(this !=& other){
        free();
        moveFrom(std::move(other));
    }
    return *this;
}

template<class T>
Collection<T>& Collection<T>::operator=(const Collection &other) {
    if(this !=& other){
        free();
        copyFrom(other);
    }
    return *this;
}

template<class T>
Collection<T>::~Collection() {
    free();
}

template<class T>
void Collection<T>::moveFrom(Collection &&other) {

    capacity = other.capacity;
    size = other.size;
    list = other.list;

    other.list = nullptr;
    other.capacity = other.size = 0;

}

template<class T>
void Collection<T>::copyFrom(const Collection &other) {

    size = other.size;
    capacity = other.capacity;

    list = new T*[capacity];

    for(int i = 0; i < size;i++){
        list[i] = other.list[i]->clone();
    }

}

template<class T>
Collection<T>::Collection(Collection<T> &&other) noexcept {
    moveFrom(std::move(other));
}

template<class T>
Collection<T>::Collection(const Collection<T> &other) {
    copyFrom(other);
}

template<class T>
T &Collection<T>::operator[](unsigned int x) const {
    return this[x];
}

template<class T>
T &Collection<T>::operator[](unsigned int x) {
    if(x > size)
        throw std::out_of_range("index is out of bounds");
    return list[x];
}

template<class T>
void Collection<T>::print() const {
    if(isEmpty())throw std::logic_error("collection is empty");
    for(int i = 0 ; i < size; i++){
        list[i]->print();
    }

}

template<class T>
void Collection<T>::add(const T& el){

    if(size == capacity){
        resize(capacity*2);
    }
    list[size++] = new T(el);
}

template<class T>
Collection<T>::Collection() {
    capacity = size = 0;
    list = new T*[0];
}

template<class T>
void Collection<T>::resize(int newCapacity) {

    if(!newCapacity)newCapacity++;

    T** newList = new T*[newCapacity];

    for(int i = 0; i < size;i++){
        newList[i] =  list[i];
    }

    delete list;

    capacity = newCapacity;
    list = newList;
}


template<class T>
void Collection<T>::free() {

    for (size_t i = 0; i < size; i++)
        delete list[i];
    delete[] list;
    size = capacity = 0;
}


#endif //COLLECTION_H
