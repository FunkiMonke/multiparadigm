#ifndef _PUBLICATION_H_
#define _PUBLICATION_H_ 
#include <string>
using namespace std;
//header class

//forward declaration
class Member;
//class definiation - parent/base class for inheritance for book, journal and magazine
class Publication
{
//inherited fields
protected:
    string ID;
    string title;
    string author;
    string genre;
    int pageCount;
    bool availability;
    int penaltyDays;
    int penaltyCost;
    Member* reserver;
//inherited methods
public:
    Publication();
    Publication(string id, string t, string a, string g, int pg, bool torf, int pd, int pc);
    string getID();
    void setID(string id);
    string getTitle();
    void setTitle(string t);
    string getAuthor();
    void setAuthor(string a);
    string getGenre();
    void setGenre(string g);
    int getPageCount();
    void setPageCount(int pg);
    bool getAvailability();
    void setAvailability(bool torf);
    int getPenaltyDays();
    void setPenaltyDays(int pd);
    int getPenaltyCost();
    Member* getReserver();
    void setReserver(Member* m);
};
#endif