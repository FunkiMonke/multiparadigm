#include "Member.h"

//Constructor - sets fields to empty values
Member::Member()
{
    memID = " ";
    name = " ";
}

//Constructor - sets fields to inputted values
Member::Member(string i, string n)
{
    memID = i;
    name = n;
}

//method to return memID
string Member::getMemId()
{
    return memID;
}

//method to set memID
void Member::setMemId(string i)
{
    memID = i;
}

//method to return name
string Member::getName()
{
    return name;
}

//method to set name 
void Member::setName(string n)
{
    name = n;
}

//method to return the list of items the member holds
vector<Publication*> Member::getList()
{
    return list;
}

//method to add a borrowed item to the member's list - prints error line if the member holds it already and doesnt add item
void Member::borrowPublication(Publication* p)
{
    for(Publication* item: list)
    {
        if (item->getID() == p->getID())
        {
            cout<<"Member already holds this."<<endl;
            return;
        }
        
    }
    list.push_back(p);
    p->setAvailability(false);
}

//method to return item and remove from member's list - prints error line if the item isnt in their list
void Member::returnPublication(Publication* p)
{
    int count = 0;
    bool exists = false;
    for(Publication* item : list)
    {
        if (item->getTitle() == p->getTitle())
        {
            item->setAvailability(true);
            list.erase(list.begin()+count);
            exists = true;
        }  
        count++;
    }
    if (!exists)
    {
        cerr<<"this member does not own this book, nothing changes\n";
    }
    
}

//method to display all items in the list
void Member::displayList()
{
    for (Publication* item : list)
    {
        cout<<item->getTitle()<<endl;
    }
}

