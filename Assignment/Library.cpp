#include "Library.h"

void Library::addBook(Book b)
{
    shelf.push_back(b);
    b.setAvailability(false);
}

void Library::removeBook(Book b)
{
    for(Book f : shelf)
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

void Library::displayBooks()
{
    for(Book f : shelf)
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
    for(Book B : shelf)
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
            cout<<"Book not Available";
        }
    }
}

void Library::save()
{
    ofstream bookOutput("Test.txt");
    ofstream memberOutput("Test2.txt");
    if (!bookOutput)
    {
        cerr<<"bookOutput stream not made";
        return;
    }

    if (!memberOutput)
    {
        cerr<<"memberOutput stream not made";
        return;
    }
    
    for(Book b : shelf)
    {
        bookOutput<<b.getID()<<" ";
        bookOutput<<"\""<<b.getTitle()<<"\" ";
        bookOutput<<"\""<<b.getAuthor()<<"\" ";
        bookOutput<<"\""<<b.getGenre()<<"\" ";
        bookOutput<<b.getPageCount()<<" ";
        bookOutput<<b.getAvailability()<<endl;
    }
    for(Member m : memList)
    {
        memberOutput<<m.getMemId()<<" "<<m.getName()<<" ";
        for(Book b : m.getList())
        {
            memberOutput<<b.getID()<<" ";
        }
        memberOutput<<endl;
    }

    memberOutput.close();
    bookOutput.close();
}

void Library::load()
{
    ifstream bookInput("books.txt");
    ifstream memberInput("members.txt");
    string line = " ";
    string data;

    if (!bookInput)
    {
        cerr<<"bookinput stream not made";
        return;
    }

    if (!memberInput)
    {
        cerr<<"memberinput stream not made";
        return;
    }

    while (getline(bookInput, line))
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

        addBook(b);
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
                    for(Book b : shelf)
                    {
                        if (b.getID() == data)
                        {
                            m.borrowBook(b);
                            exists = true;
                            break;
                        }
                    }
                    if (!exists)
                    {
                        Book nb;
                        nb.setID(data);
                        addBook(nb);
                        m.borrowBook(nb);
                    }
                    break;
            }
            dataCount++;
        }
        addMember(m);
    }
}


