#include "Member.h"

Member::Member()
{
    memID = " ";
    name = " ";
}

Member::Member(string i, string n)
{
    memID = i;
    name = n;
}

string Member::getMemId()
{
    return memID;
}

void Member::setMemId(string i)
{
    memID = i;
}

string Member::getName()
{
    return name;
}

void Member::setName(string n)
{
    name = n;
}

vector<Publication> Member::getList()
{
    return list;
}

void Member::borrowPublication(Publication b)
{
    list.push_back(b);
    b.setAvailability(false);
}

void Member::returnPublication(Publication b)
{
    for(Publication r : list)
    {
        if (r.getTitle() == b.getTitle())
        {
            r.setAvailability(true);
            list.push_back(r);
        }   
    }
}

void Member::displayList()
{
    for (Publication b : list)
    {
        cout<<b.getTitle()<<endl;
    }
}

