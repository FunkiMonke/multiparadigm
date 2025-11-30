#include "Member.h"

Member::Member()
{
    memID = " ";
    name = " ";
}

Member::Member(int i, string n)
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

vector<Book> Member::getList()
{
    return list;
}

void Member::borrowBook(Book b)
{
    list.push_back(b);
    b.setAvailability(false);
}

void Member::returnBook(Book b)
{
    for(Book r : list)
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
    for (Book b : list)
    {
        cout<<b.getTitle()<<endl;
    }
}

