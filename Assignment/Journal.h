#ifndef _JOURNAL_H_
#define _JOURNAL_H_
#include "Publication.h"
#include <string>
using namespace std;

class Journal:public Publication
{
private:
    int volume;
public:
    Journal();
    Journal(string id, string t, string a, string g, int pg, bool torf, int pd, int in);
    int getVolume();
    void setVolume(int v);
};
#endif 