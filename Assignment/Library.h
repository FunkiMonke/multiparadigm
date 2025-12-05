#ifndef _LIBRARY_H_
#define _LIBRARY_H_

#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include "Member.h"
#include "Publication.h"
#include "Journal.h"
#include "Book.h"
#include "Magazine.h"

using namespace std;
//header - in here as its a template class, mainly uses publication*
template<class T>
class Library
{
private:
//fields - one to store publications, one to store members
    vector<T> shelf;
    vector<Member*> memList;

//methods
public:
    Library();
    ~Library();
    void addPublication(T item);
    void removePublication(T item);
    void addMember(Member* m);
    void removeMember(Member* m);
    Member* getMember(string id);
    void borrowPublication(string id, Member* m);
    void returnPublication(string id, Member* m);
    void displayPublications();
    void displayMembers();
    void search();
    void calculatePenalty(T item);
    void updatePenalties();
    void save();
    void load();
};

//constructor
template<typename T>
Library<T>::Library()
{
    cout<<"Library System Created.\n";
}

//deconstructor - clears all memory used by fields
template<typename T>
Library<T>::~Library()
{
    for(T item : shelf)
    {
        delete(item);
    }

    for(Member* m : memList)
    {
        delete(m);
    }
}

//method to add publications to the system - checks if its in already and if not, adds it in
template <typename T>
void Library<T>::addPublication(T p)
{
    for (T item : shelf)
    {
        if (item->getID() == p->getID())
        {
            cout<<"This is already in the system."<<endl;
            return;
        }
    }
    shelf.push_back(p);
    p->setAvailability(true);
}

//method to remove publications - checks if any match the id, if yes, remove. if not returns error
template <typename T>
void Library<T>::removePublication(T p)
{
    bool exists = false;
    for(Publication item : shelf)
    {
        int count = 0;
 
        if (item.getID() == p.getID())
        {
            item.setAvailability(false);
            shelf.erase(shelf.begin()+count);
            exists = true;
            break;
        }  
        count++; 
    }
    if(!exists)
    {
        cerr<<"This publication does not exist/Wrong ID\n";
        return;
    }

}

//method to add members to the system - checks if they're in already and if not, adds them in
template <typename T>
void Library<T>::addMember(Member* m)
{
    for (Member* inList : memList)
    {
        if (inList->getMemId() == m->getMemId())
        {
            cout<<"This person is already in the system."<<endl;
            return;
        }
    }
    memList.push_back(m);
}

//method to remove publications - checks if any match the id, if yes, remove. if not returns error
template <typename T>
void Library<T>::removeMember(Member* m)
{
    int count = 0;
    bool exists = false;
    for(Member* item : memList)
    {
        if (item->getMemId() == m->getMemId())
        {
            memList.erase(memList.begin()+count);
            exists = true;
            break;
        }
        count++;  
    }

    if(!exists)
    {
        cerr<<"ID not valid or member doesnt exist.\n";
        return;
    }

}

//method to get a member based on ID, prints error if not found
template<typename T>
Member* Library<T>::getMember(string id)
{
    try
    {
        for(Member* inList : memList)
        {
            if (id == inList->getMemId())
            {
                return inList;
            }
        }
        throw 24;
    }
    catch(int error)
    {
        std::cerr << error << "\nNot in list or wrong ID";
        return nullptr;
    }
}


//method to let a member borrow a publication. prints error if the book or member isnt found
template<typename T>
void Library<T>::borrowPublication(string id, Member* m)
{
    try
    {
        for(T item : shelf)
        {
            if (item->getID()==id)
            {
                m->borrowPublication(item);
                return;
            }
        }
        throw 25;
    }
    catch(int error)
    {
        std::cerr << error << "\n publication doesn't exist or wrong id";
        return;
    }
    
}

//method to let a member return a publication. prints error if the book or member isnt found
template<typename T>
void Library<T>::returnPublication(string id, Member* m)
{
    try
    {
        for(T item : shelf)
        {
            if (item->getID()==id)
            {
                m->returnPublication(item);
                return;
            }
        }
        throw 25;
    }
    catch(int error)
    {
        std::cerr << error << "\n publication doesn't exist or wrong id";
        return;
    }
}

//method to display all publications in the system - prints their ID
template <typename T>
void Library<T>::displayPublications()
{
    for(T item : shelf)
    {
        cout<<item->getID()<<endl;
    }
}

//method to display all members in the system - prints their ID
template <typename T>
void Library<T>::displayMembers()
{
    for(Member* mem : memList)
    {
        cout<<mem->getName()<<" ";
        for(T item : mem->getList())
        {
            cout<<item->getID()<<" ";
        }
        cout<<endl;
    }
}

//method to search with different criteria, then prints whatever matches - takes in search catagory and search term - throws error on invalid argument
template <typename T>
void Library<T>::search()
{
    try
    {
        int userChoice=0;
        string userSearch;
        cout<<"Specify Search Criteria: "<<endl;
        cout<<"1: ID\n2: Title\n3: Author\n4: Genre\n5: Availability"<<endl;
        while (!userChoice > 0 && !userChoice <6)
        {
            cin>>userChoice;
            if (userChoice > 0 && userChoice <6)
            {
                break;
            }
            cout<<"invalid input, please retry.\n";
        }
        cout<<"Enter Search Term:\t";
        cin.ignore();
        getline(cin, userSearch);
        switch (userChoice)
        {
            case 1:
                for(T item : shelf)
                {
                    if (item->getID() != userSearch)
                    {
                        continue;
                    }
                    if (!item->getAvailability())
                    {
                        cout<<"\nThis publication is not availabile"<<endl;
                    }
                    else
                    {
                        cout<<"\n"<<item->getID()<<" | "<<item->getTitle()<<" | "<<item->getAuthor()<<endl;
                    }   
                }
                break;

            case 2:
                for(T item : shelf)
                {
                    if (item->getTitle() != userSearch)
                    {
                        continue;
                    }
                    if (!item->getAvailability())
                    {
                        cout<<"\nThis publication is not availabile"<<endl;
                    }
                    else
                    {
                        cout<<"\n"<<item->getID()<<" | "<<item->getTitle()<<" | "<<item->getAuthor()<<endl;
                    }
                }
                break;

            case 3:
                for(T item : shelf)
                {
                    if (item->getAuthor() != userSearch)
                    {
                        continue;
                    }
                    if (!item->getAvailability())
                    {
                        cout<<"\nThis publication is not availabile"<<endl;
                    }
                    else
                    {
                        cout<<"\n"<<item->getID()<<" | "<<item->getTitle()<<" | "<<item->getAuthor()<<endl;
                    }   
                }
                break;

            case 4:
                for(T item : shelf)
                {
                    if (item->getAuthor().find(userSearch)== string::npos)
                    {
                        continue;
                    }
                    if (!item->getAvailability())
                    {
                        cout<<"\nThis publication is not availabile"<<endl;
                    }
                    else
                    {
                        cout<<"\n"<<item->getID()<<" | "<<item->getTitle()<<" | "<<item->getAuthor()<<endl;
                    }   
                }
                break;

            case 5:
                for(T item : shelf)
                {
                    if (item->getAvailability())
                    {
                        cout<<"\n"<<item->getID()<<" | "<<item->getTitle()<<" | "<<item->getAuthor()<<endl;
                    }
                }
                break;
        }
    }
    catch(const std::invalid_argument& e)
    {
        std::cerr<<"Invalid input, please ensure correct type is entered. \t"<< e.what() << '\n';
    }
}

//method to print the current penalty cost.
template <typename T>
void Library<T>::calculatePenalty(T item)
{
    cout << "\n" << item->getPenaltyDays() * item->getPenaltyCost();
}

//method to update penalties for all items in the system
template <typename T>
void Library<T>::updatePenalties()
{
    for (T item : shelf)
    {
        item->setPenaltyDays(item->getPenaltyDays()+1);
    }
}

//method to save data to a file - prints error if trouble on creating/writing to file
template <typename T>
void Library<T>::save()
{
    ofstream PublicationOutput("Test.txt");
    ofstream memberOutput("Test2.txt");
    if (!PublicationOutput)
    {
        cerr<<"PublicationOutput stream not made";
        return;
    }

    if (!memberOutput)
    {
        cerr<<"memberOutput stream not made";
        return;
    }
    
    for(T item : shelf)
    {
        PublicationOutput<<item->getID()<<" ";
        PublicationOutput<<"\""<<item->getTitle()<<"\" ";
        PublicationOutput<<"\""<<item->getAuthor()<<"\" ";
        PublicationOutput<<"\""<<item->getGenre()<<"\" ";
        PublicationOutput<<item->getPageCount()<<" ";
        PublicationOutput<<item->getAvailability()<<" ";
        PublicationOutput<<item->getPenaltyDays()<<endl;
    }
    for(Member* m : memList)
    {
        memberOutput<<m->getMemId()<<" "<<m->getName()<<" ";
        for(T item : m->getList())
        {
            memberOutput<<item->getID()<<" ";
        }
        memberOutput<<endl;
    }

    memberOutput.close();
    PublicationOutput.close();
}

//method to load data from a file to the system, creates new objects based on ID, prints error if issue with creating/reading file
template <typename T>
void Library<T>::load()
{
    try
    {
        ifstream PublicationInput("books.txt");
        ifstream memberInput("members.txt");
        string line = " ";
        string data;

        if (!PublicationInput)
        {
            cerr<<"Publicationinput stream not made";
            return;
        }

        if (!memberInput)
        {
            cerr<<"memberinput stream not made";
            return;
        }

        while (getline(PublicationInput, line))
        {
            stringstream splitter(line);
            //book specifically here since all in the original txt file were books
            Book* b = nullptr;            
            b = new Book();
            for (int i = 0; i < 6; i++)
            {
                do
                {
                    getline(splitter, data, '"');
                }
                while(data == " ");
                switch (i)
                {
                    case 0:
                        data.erase(4);
                        b->setID(data);
                        break;

                    case 1:
                        b->setTitle(data);
                        break;

                    case 2:
                        b->setAuthor(data);
                        break;
                    case 3:
                        b->setGenre(data);
                        break;

                    case 4:
                        b->setPageCount(stoi(data));
                        break;

                    case 5:
                        string realAvail = data.substr(data.find_last_of(' ')+1, 1);
                        b->setAvailability(stoi(data));
                        break;
                }
            }

            addPublication(b);
        }
    

        while (getline(memberInput, line))
        {
            stringstream splitter(line);
            Member* m = nullptr;
            m = new Member();
            int dataCount = 0;

            while (getline(splitter, data,' '))
            {
                switch (dataCount)
                {
                    case 0:
                        m->setMemId(data);
                        break;
                    
                    case 1:
                        m->setName(data);
                        break;
                    
                    default:
                        bool exists = false;
                        for(T item : shelf)
                        {
                            if (item->getID() == data)
                            {
                                m->borrowPublication(item);
                                exists = true;
                                break;
                            }
                        }
                        if (!exists)
                        {
                            Publication* newItem = nullptr;
                            switch(data.at(0))
                            {
                                case 'J':
                                    newItem = new Journal();
                                    break;
                                case 'B':
                                    newItem = new Book();
                                    break;
                                case 'm':
                                    newItem = new Magazine();
                                    break;
                                case 'P':
                                    newItem = new Publication();
                                    break;
                                default:
                                    throw 10; //throws error here if it reads in an invalid type that isnt specified 
                            }
                            newItem->setID(data);
                            addPublication(newItem);
                            m->borrowPublication(newItem);
                        }
                        break;
                }
                dataCount++;
            }
            addMember(m);
        }
    }

    catch(int error)
    {
        std::cerr << error << "Unrecognized type, cannot add to system.\n";
        return;
    }

    catch(bad_alloc &e)
    {
        cerr<<"Bad allocation thrown, pointer isnt null before use\n";
        return;
    }
}
#endif