#include <iostream>
#include "Library.h"
#include "Book.h"
#include "Member.h"
#include "Journal.h"
using namespace std;

int main() 
{
    Library l;
    l.load();
    l.save();
    Journal j("J101", "Journaly", "auta", "jork", 200, true, 17);
    Member m("M119", "Rupert");
    
    l.addPublication(j);
    l.displayPublications();
    l.displayMembers();
    return 0;
}