#ifndef _LIBRARY_H_
#define _LIBRARY_H_

#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include "Member.h"
#include "Book.h"
using namespace std;

class Library
{
private:
    vector<Book> shelf;
    vector<Member> memList;
public:
    void addBook(Book b);
    void removeBook(Book b);
    void addMember(Member M);
    void removeMember(Member m);
    void displayBooks();
    void displayMembers();
    void search(string t);
    void save();
    void load();

    void save2();
    void load2();
};
#endif