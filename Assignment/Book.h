#ifndef _BOOK_H_
#define _BOOK_H_ 
#include <string>
#include "Publication.h"
using namespace std;

class Book: public Publication
{
private:
    bool hardback;
public:
    Book();
    Book(string id, string t, string a, string g, int pg, bool torf, int pd, bool hb);
    bool getHardback();
    void setHardback(bool hb);
};
#endif