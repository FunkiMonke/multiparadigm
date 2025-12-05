#ifndef _BOOK_H_
#define _BOOK_H_ 
#include <string>
#include "Publication.h"
using namespace std;
//header - inherits from publication
class Book: public Publication
{
//fields
private:
    bool hardback;
//methods
public:
    Book();
    Book(string id, string t, string a, string g, int pg, bool torf, int pd, bool hb);
    bool getHardback();
    void setHardback(bool hb);
};
#endif