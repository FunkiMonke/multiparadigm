#ifndef _BOOK_H_
#define _BOOK_H_ 
#include <string>
using namespace std;

class Book
{
private:
    string ID;
    string title;
    string author;
    string genre;
    int pageCount;
    bool availability;

public:
    Book();
    Book(string id, string t, string a, string g, int pg, bool torf);
    string getID();
    void setID(string id);
    string getTitle();
    void setTitle(string t);
    string getAuthor();
    void setAuthor(string a);
    string getGenre();
    void setGenre(string a);
    int getPageCount();
    void setPageCount(int pg);
    bool getAvailability();
    void setAvailability(bool torf);
};
#endif