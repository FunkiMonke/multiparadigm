#ifndef _LIBRARY_H_
#define _LIBRARY_H_

#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include "Member.h"
#include "Publication.h"
using namespace std;

class Library
{
private:
    vector<Publication> shelf;
    vector<Member> memList;
public:
    void addPublication(Publication b);
    void removePublication(Publication b);
    void addMember(Member M);
    void removeMember(Member m);
    void displayPublications();
    void displayMembers();
    void search(string t);
    void save();
    void load();
};
#endif