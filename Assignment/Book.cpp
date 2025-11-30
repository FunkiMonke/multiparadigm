#include "Book.h"

Book::Book()
{
    ID = "id";
    title = "title";
    author = "author";
    genre = "genre";
    pageCount = 0;
    availability = true;
}

Book::Book(string id, string t, string a, string g, int pg, bool torf)
{
    ID = id;
    title = t;
    author = a;
    genre = g;
    pageCount = pg;
    availability = torf;
}

string Book::getID()
{
    return ID;
}

void Book::setID(string id)
{
    ID = id;
}

string Book::getTitle()
{
    return title;
}

void Book::setTitle(string t)
{
    title = t;
}

string Book::getAuthor()
{
    return author;
}

void Book::setAuthor(string a)
{
    author = a;
}

string Book::getGenre()
{
    return genre;
}

void Book::setGenre(string g)
{
    genre = g;
}

int Book::getPageCount()
{
    return pageCount;
}

void Book::setPageCount(int pg)
{
    pageCount = pg;
}

bool Book::getAvailability()
{
    return availability;
}

void Book::setAvailability(bool torf)
{
    availability = torf;
}