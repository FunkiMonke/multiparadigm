#include <iostream>
using namespace std;

void printStars(int xNum, int yNum)
{
    for (int i = 0; i < yNum; i++)
    {
        for (int j = 0; j < xNum; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
    
}

void diamond(int num)
{
    string s(num,'a');

    
    for (int i = 0; i < num; i++)
    {
        for (int j = 1; j < num-i; j++)
        {
            cout<<" ";
        }
        for (int k = 1; k <= 2*i-1; k++)
        {
            cout<<"*";
        }
        cout<<endl;
    }
}

int main()
{
    diamond(6);
}