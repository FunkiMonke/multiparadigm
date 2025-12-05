#include <iostream>
#include "Library.h"
#include "Book.h"
#include "Member.h"
#include "Journal.h"
using namespace std;

//Tester method to run all tests - each test is commented and has the expected outcome - all passed
int Tests()
{
    Library<Publication*> l;
    //Test 1 - load from txt file - should display all books and members
    l.load();
    l.displayPublications();
    l.displayMembers();

    //test2 - add new item to the shelf
    //2.1 - add a new one - should display all items, including the new addition
    Publication* k = nullptr;
    k = new Journal("J101", "Journaly", "auta", "jork", 200, true, 5, 17);
    l.addPublication(k);
    l.displayPublications();
    //2.2 - add an item that already exists - should print out an error log and the display should be the same as before
    Publication* duplicateCheck = nullptr;
    duplicateCheck = new Book("B101", "The Power of Positive Thinking", "Norman Vincent Peale", "Motivational, Spiritual", 240, 1, 5, 1);
    l.addPublication(duplicateCheck);
    l.displayPublications();

    //test3 - add a new member
    //3.1 - add a new one - should display all members, including the new addition, with what they have borrowed
    l.displayMembers();
    Member* m = nullptr;
    m = new Member("M119", "Rupert");
    l.addMember(m);
    l.displayMembers();
    //3.2 - add a member that already exists - should print out an error log and the display should be the same as before
    Member* m2 = nullptr;
    m2 = new Member("M105", "Jane");
    l.addMember(m2);
    l.displayMembers();

    //test4 - have a member borrow an item 
    //4.1 - an item they already have - should print out an error log and the display should be the same as before
    l.borrowPublication("B106", l.getMember("M106"));
    l.displayMembers();
    //4.2 - an item they dont have - should display all members, new item should appear in list
    l.borrowPublication("B101", l.getMember("M106"));
    l.displayMembers();

    //test5 - return an item 
    //5.1 - return an item they hold - the display should update to show they no longer possess it
    l.returnPublication("B106", l.getMember("M106"));
    l.returnPublication("B101", l.getMember("M106"));
    l.displayMembers();
    //5.2 - return item they dont hold - should print error message, display remains unchanged
    l.returnPublication("B107", l.getMember("M106"));
    l.displayMembers();

    //test6 - search on criteria 
    l.search(); //searching based on a title + "Awaken the Giant Within" - should display the id, title and author
    l.search(); //searching based on author + "Tony Robbins" - should display the id, title and author

    //test7 - repeat of test 4 with a different member and book - should print out an error log and the display should be the same as before
    l.borrowPublication("B109", l.getMember("M109"));
    l.displayMembers();

    //test8 - save to the system - "test.txt" and "test2.txt" should be created and print all data correctly, resembling the original txt files with the additonal parameter in the lines
    l.save();

    //unique test - update penalties - should print original penalty then the new updated penalty
    l.calculatePenalty(k);
    l.updatePenalties();
    l.calculatePenalty(k);
    return 0;
}

//main - calls Tests to begin testing
int main() 
{
    Tests();
    return 0;
}