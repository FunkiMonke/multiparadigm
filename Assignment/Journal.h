#ifndef _JOURNAL_H_
#define _JOURNAL_H_
#include "Publication.h"
#include <string>
using namespace std;
//header - inherits from publication
class Journal:public Publication
{
private:
//fields
    int volume;
//methods
public:
    Journal();
    Journal(string id, string t, string a, string g, int pg, bool torf, int pd, int in);
    int getVolume();
    void setVolume(int v);
};
#endif 