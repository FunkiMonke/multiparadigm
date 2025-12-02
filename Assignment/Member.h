#ifndef _MEMBER_H_
#define _MEMBER_H_ 

#include <iostream>
#include <vector>
#include "Publication.h"
using namespace std;

class Member
{
private:
    string memID;
    string name;
    vector<Publication> list;
public:
    Member();
    Member(string i, string n);
    string getMemId();
    void setMemId(string i);
    string getName();
    void setName(string t);
    vector<Publication> getList();
    void borrowPublication(Publication b);
    void returnPublication(Publication b);
    void displayList();
};
#endif
