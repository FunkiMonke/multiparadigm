#include "Journal.h"
//Constructor - sets all fields to default values
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

//Constructor - sets all fields to inputted values
Journal::Journal(string id, string t, string a, string g, int pg, bool torf, int pd, int v)
{
    ID = id;
    title = t;
    author = a;
    genre = g;
    pageCount = pg;
    availability = torf;
    penaltyDays = pd;
    penaltyCost = 3;
    volume = v;
}

//method to get the volume number
int Journal::getVolume()
{
    return volume;
}
//method to set the volume number
void Journal::setVolume(int v)
{
    volume = v;
}