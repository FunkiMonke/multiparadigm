#include "Publication.h"

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

string Publication::getID()
{
    return ID;
}

void Publication::setID(string id)
{
    ID = id;
}

string Publication::getTitle()
{
    return title;
}

void Publication::setTitle(string t)
{
    title = t;
}

string Publication::getAuthor()
{
    return author;
}

void Publication::setAuthor(string a)
{
    author = a;
}

string Publication::getGenre()
{
    return genre;
}

void Publication::setGenre(string g)
{
    genre = g;
}

int Publication::getPageCount()
{
    return pageCount;
}

void Publication::setPageCount(int pg)
{
    pageCount = pg;
}

bool Publication::getAvailability()
{
    return availability;
}

void Publication::setAvailability(bool torf)
{
    availability = torf;
}

int Publication::getPenaltyDays()
{
    return penaltyDays;
}

void Publication::setPenaltyDays(int pd)
{
    penaltyDays = pd;
}

int Publication::getPenaltyCost()
{
    return penaltyCost;
}
