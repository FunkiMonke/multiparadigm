#ifndef _MEMBER_H_
#define _MEMBER_H_ 

#include <iostream>
#include <vector>
#include "Publication.h"
using namespace std;
//header - class declaration
class Member
{
//fields
private:
    string memID;
    string name;
    vector<Publication*> list;
//methods
public:
    Member();
    Member(string i, string n);
    string getMemId();
    void setMemId(string i);
    string getName();
    void setName(string t);
    vector<Publication*> getList();
    void borrowPublication(Publication* p);
    void returnPublication(Publication* p);
    void displayList();
};
#endif
