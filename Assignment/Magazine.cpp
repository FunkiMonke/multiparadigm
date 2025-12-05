#include "Magazine.h"

//Constructor - sets all fields to default values
Magazine::Magazine()
{
    ID = "id";
    title = "title";
    author = "author";
    genre = "genre";
    pageCount = 0;
    availability = true;
    penaltyDays = 0;
    penaltyCost = 2;
    issueNum = 0;
}

//Constructor - sets all fields to inputted values
Magazine::Magazine(string id, string t, string a, string g, int pg, bool torf, int pd, int in)
{
    ID = id;
    title = t;
    author = a;
    genre = g;
    pageCount = pg;
    availability = torf;
    penaltyDays = pd;
    penaltyCost = 2;
    issueNum = in;
}

//method to return value of issueNum
int Magazine::getIssueNum()
{
    return issueNum;
}

//method to set value of issueNum
void Magazine::setIssueNum(int in)
{
    issueNum = in;
}