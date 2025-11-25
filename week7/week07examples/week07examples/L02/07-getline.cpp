#include <string>
#include <iostream>

using namespace std;

int main() {

  string name;

  cout << "Please enter your full name: ";
  cin >> name;
  cin.ignore( 256, '\n' );

  cout << "Welcome " << name << endl;

  cout << "Please re-enter your full name: ";

  getline( cin, name );

  cout << "Thanks, " << name << endl;

  return 0; 

}

