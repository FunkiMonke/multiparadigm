#include "Library.h"
//#include "Journal.h"
#include "Book.h"
#include "Magazine.h"

void Library::addPublication(Publication b)
{
    shelf.push_back(b);
    b.setAvailability(false);
}

void Library::removePublication(Publication b)
{
    for(Publication f : shelf)
    {
        if (f.getTitle() == b.getTitle())
        {
            f.setAvailability(true);
            shelf.push_back(f);
            break;
        }   
    }
}

void Library::addMember(Member m)
{
    memList.push_back(m);
}

void Library::removeMember(Member m)
{
    for(Member f : memList)
    {
        if (f.getMemId() == m.getMemId())
        {
            memList.push_back(f);
            break;
        }   
    }
}

void Library::displayPublications()
{
    for(Publication f : shelf)
    {
        cout<<f.getTitle()<<endl;
    }
}

void Library::displayMembers()
{
    for(Member f : memList)
    {
        cout<<f.getName()<<endl;
    }
}

void Library::search(string t)
{
    for(Publication B : shelf)
    {
        if (B.getTitle() != t||B.getID() != t)
        {
            continue;
        }
        if (B.getAvailability())
        {
            cout<<B.getTitle()<<endl;
        }
        else
        {
            cout<<"Publication not Available";
        }
    }
}

void Library::save()
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
    
    for(Publication b : shelf)
    {
        PublicationOutput<<b.getID()<<" ";
        PublicationOutput<<"\""<<b.getTitle()<<"\" ";
        PublicationOutput<<"\""<<b.getAuthor()<<"\" ";
        PublicationOutput<<"\""<<b.getGenre()<<"\" ";
        PublicationOutput<<b.getPageCount()<<" ";
        PublicationOutput<<b.getAvailability()<<endl;
    }
    for(Member m : memList)
    {
        memberOutput<<m.getMemId()<<" "<<m.getName()<<" ";
        for(Publication b : m.getList())
        {
            memberOutput<<b.getID()<<" ";
        }
        memberOutput<<endl;
    }

    memberOutput.close();
    PublicationOutput.close();
}

void Library::load()
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
        Book b;
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
                    b.setID(data);
                    break;

                case 1:
                    b.setTitle(data);
                    break;

                case 2:
                    b.setAuthor(data);
                    break;
                case 3:
                    b.setGenre(data);
                    break;

                case 4:
                    b.setPageCount(stoi(data));
                    break;

                case 5:
                    string realAvail = data.substr(data.find_last_of(' ')+1, 1);
                    b.setAvailability(stoi(data));
                    break;
            }
        }

        addPublication(b);
    }
    

    while (getline(memberInput, line))
    {
        stringstream splitter(line);
        Member m;
        int dataCount = 0;

        while (getline(splitter, data,' '))
        {
            switch (dataCount)
            {
                case 0:
                    m.setMemId(data);
                    break;
                
                case 1:
                    m.setName(data);
                    break;
                
                default:
                    bool exists = false;
                    for(Publication b : shelf)
                    {
                        if (b.getID() == data)
                        {
                            m.borrowPublication(b);
                            exists = true;
                            break;
                        }
                    }
                    if (!exists)
                    {
                        Publication nb;
                        nb.setID(data);
                        addPublication(nb);
                        m.borrowPublication(nb);
                    }
                    break;
            }
            dataCount++;
        }
        addMember(m);
    }
}


