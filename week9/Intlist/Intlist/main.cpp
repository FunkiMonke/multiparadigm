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

  while (!int_list.Empty())
  {
    cout << "Enter number to delete:  ";
    cin >> object;
    int_list.Delete(object);
    cout << "List: " << int_list << endl;
  }
  return 0;
}

