#include <iostream>
#include "Library.h"
#include "Book.h"
#include "Member.h"
using namespace std;

int main() 
{
    Library l;
    l.load();
    l.save();

    l.displayBooks();
    l.displayMembers();
    return 0;
}