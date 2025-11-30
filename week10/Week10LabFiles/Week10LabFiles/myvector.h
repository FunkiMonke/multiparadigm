#ifndef MYVEC_H 
#define MYVEC_H
#include<iostream>
using namespace std;

// Forward declaration of templates required for templated friend function
template <typename T> class MyVector;
template <typename T> ostream& operator<<( ostream&, const MyVector<T>& );

template <class T>
class MyVector {
    private:
		T* contents;
		int current_size;
        int capacity;
	public:
		MyVector();
        ~MyVector();
		void push_back(T data);
        T pop_back();
        void assign(int n, T value);
        int size();
        T at(int i);
        T front();
        T back();

        friend ostream& operator<< <T>( ostream&, const MyVector<T>& );
};

#endif
