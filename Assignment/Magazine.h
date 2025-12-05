#ifndef _MAGAZINE_H_
#define _MAGAZINE_H_
#include "Publication.h"
#include <string>
using namespace std;

//header - inheritis from publication
class Magazine:public Publication
{
private:
//fields
    int issueNum;
//methods
public:
    Magazine();
    Magazine(string id, string t, string a, string g, int pg, bool torf, int pd, int in);
    int getIssueNum();
    void setIssueNum(int in);
};
#endif 