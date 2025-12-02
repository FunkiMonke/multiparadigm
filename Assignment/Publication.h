#ifndef _PUBLICATION_H_
#define _PUBLICATION_H_ 
#include <string>
using namespace std;
class Publication
{
protected:
    string ID;
    string title;
    string author;
    string genre;
    int pageCount;
    bool availability;
    int penaltyDays;
    int penaltyCost;
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
};
#endif