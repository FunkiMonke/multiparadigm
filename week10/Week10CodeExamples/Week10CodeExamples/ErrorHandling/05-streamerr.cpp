#include <iostream>

using namespace std;

int main() {
  int a;

  cout << "Enter an integer: ";

  cin >> a;  // Try skipping this input with CTRL-D, or send echo "A" or echo "" through a pipe
  cout << "Your input was: " << a << endl;

  cout << "Good Fail Bad EOF bits:" << endl;
  cout << cin.good() << cin.fail() << cin.bad() << cin.eof() << endl;

  if (!cin) {
      cerr << "Input error." << endl;
      return 1;
  }

  return 0;
}

