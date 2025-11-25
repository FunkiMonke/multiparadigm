#include <iostream>
using namespace std;

namespace other {
  int x = 24;
}

using namespace other;
int main() {
  cout << "other::x = " << x << endl;
  cout << "x = " << x << endl; 
}
