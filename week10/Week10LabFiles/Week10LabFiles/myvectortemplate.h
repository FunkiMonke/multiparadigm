#ifndef MYVECTEMPLATE_H 
#define MYVECTEMPLATE_H 
#include "myvector.h"
using namespace std;

template <class T>
MyVector<T>::MyVector(){
    contents = new T[1];
    current_size = 0;
	capacity = 1;
}

template <class T>
MyVector<T>::~MyVector(){
    delete[] contents;
}

template <class T>
void MyVector<T>::push_back(T data){
    if (current_size == capacity) {
        T* tmp = new T[2 * capacity];
        for (int i = 0; i < capacity; i++) {
            tmp[i] = contents[i];
        }
        delete[] contents;
        capacity *= 2;
        contents = tmp;
    }
    contents[current_size] = data;
    current_size++;
}

template <class T>
T MyVector<T>::pop_back(){
}

template <class T>
void MyVector<T>::assign(int n, T value){
}

template <class T>
int MyVector<T>::size(){
}

template <class T>
T MyVector<T>::at(int i){
}

template <class T>
T MyVector<T>::front(){
}

template <class T>
T MyVector<T>::back(){
}

template <typename T>
ostream& operator<<( ostream& output, const MyVector<T>& v ) {
}

#endif
