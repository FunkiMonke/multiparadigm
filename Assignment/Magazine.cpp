#include "Magazine.h"

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

Magazine::Magazine(string id, string t, string a, string g, int pg, bool torf, int pd, int in)
{
    ID = id;
    title = t;
    author = a;
    genre = g;
    pageCount = pg;
    availability = torf;
    penaltyDays = pd;
    issueNum = in;
}

int Magazine::getIssueNum()
{
    return issueNum;
}

void Magazine::setIssueNum(int in)
{
    issueNum = in;
}