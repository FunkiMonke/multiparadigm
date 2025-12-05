#include "Publication.h"
//Constructor - sets fields to default values
Publication::Publication()
{
    ID = "id";
    title = "title";
    author = "author";
    genre = "genre";
    pageCount = 0;
    availability = true;
    penaltyDays = 0;
    penaltyCost = 0;
}

//Constructor - sets fields to inputted values
Publication::Publication(string id, string t, string a, string g, int pg, bool torf, int pd, int pc)
{
    ID = id;
    title = t;
    author = a;
    genre = g;
    pageCount = pg;
    availability = torf;
    penaltyDays = pd;
    penaltyCost = pc;
}

//method to return ID
string Publication::getID()
{
    return ID;
}

//method to set ID
void Publication::setID(string id)
{
    ID = id;
}

//method to return title
string Publication::getTitle()
{
    return title;
}

//method to set title
void Publication::setTitle(string t)
{
    title = t;
}

//method to return author
string Publication::getAuthor()
{
    return author;
}

//method to set author
void Publication::setAuthor(string a)
{
    author = a;
}

//method to return genre
string Publication::getGenre()
{
    return genre;
}

//method to set genre
void Publication::setGenre(string g)
{
    genre = g;
}

//method to return page count
int Publication::getPageCount()
{
    return pageCount;
}

//method to set page count
void Publication::setPageCount(int pg)
{
    pageCount = pg;
}

//method to return availabilty
bool Publication::getAvailability()
{
    return availability;
}

//method to set availability
void Publication::setAvailability(bool torf)
{
    availability = torf;
}

//method to return the penalty days
int Publication::getPenaltyDays()
{
    return penaltyDays;
}

//method to set penalty days
void Publication::setPenaltyDays(int pd)
{
    penaltyDays = pd;
}

//method to return penalty cost
int Publication::getPenaltyCost()
{
    return penaltyCost;
}

//method to return the current reserver
Member* Publication::getReserver()
{
    return reserver;
}

//method to set the reserver (unused)
void Publication::setReserver(Member* m)
{
    reserver = m;
}