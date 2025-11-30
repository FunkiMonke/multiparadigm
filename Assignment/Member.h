#ifndef _MEMBER_H_
#define _MEMBER_H_ 

#include <iostream>
#include <vector>
#include "Book.h"
using namespace std;

class Member
{
private:
    string memID;
    string name;
    vector<Book> list;
public:
    Member();
    Member(int i, string n);
    string getMemId();
    void setMemId(string i);
    string getName();
    void setName(string t);
    vector<Book> getList();
    void borrowBook(Book b);
    void returnBook(Book b);
    void displayList();
};
#endif
