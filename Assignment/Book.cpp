#include "Book.h"
//Constructor - sets all fields to default values
Book::Book()
{
    ID = "id";
    title = "title";
    author = "author";
    genre = "genre";
    pageCount = 0;
    availability = true;
    penaltyDays = 0;
    penaltyCost = 5;
    hardback = false;
}

//Constructor - sets all fields to inputted values
Book::Book(string id, string t, string a, string g, int pg, bool torf, int pd, bool hb)
{
    ID = id;
    title = t;
    author = a;
    genre = g;
    pageCount = pg;
    availability = torf;
    penaltyDays = pd;
    penaltyCost = 5;
    hardback = hb;
}

//method to retrieve if it's a hardback
bool Book::getHardback()
{
    return hardback;
}

//method to set the value of hardback
void Book::setHardback(bool hb)
{
    hardback = hb;
}

