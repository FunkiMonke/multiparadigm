#include "Journal.h"

Journal::Journal()
{
    ID = "id";
    title = "title";
    author = "author";
    genre = "genre";
    pageCount = 0;
    availability = true;
    penaltyDays = 0;
    penaltyCost = 3;
    volume = 0;
}

Journal::Journal(string id, string t, string a, string g, int pg, bool torf, int pd, int v)
{
    ID = id;
    title = t;
    author = a;
    genre = g;
    pageCount = pg;
    availability = torf;
    penaltyDays = pd;
    volume = v;
}

int Journal::getVolume()
{
    return volume;
}

void Journal::setVolume(int v)
{
    volume = v;
}