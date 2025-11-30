#include <iostream>
#include "intlist.h"
using namespace std;


int main()
{
  Intlist int_list;
  int object;

  cout << "Enter list of integers, 0 to finish: " << endl << endl;
  cin >> object;
  while (object > 0)
  {
    int_list.Insert(object);
    cin >> object;
  }

  cout << endl << "List: " << int_list << endl;

  // while (!int_list.Empty())
  // {
  //   cout << "Enter number to delete:  ";
  //   cin >> object;
  //   int_list.Delete(object);
  //   cout << "List: " << int_list << endl;
  // }

  cout<<int_list.count()<<endl;

  int_list.doubleElements();
  cout<<int_list<<endl;
  int j = int_list.getHead();
  cout<<j<<endl;
  int t;
  cin>>t;
  cout<<int_list.valueAt(t);
  cin>>t;
  cout<<int_list.occurs(t);
  int_list.insertAtEnd(69);
  cout<<int_list;
  return 0;
}
