#include <iostream>
#include <string>
using namespace std;
 
class printData {
   public:
      void print(int i) {
        cout << "Printing int: " << i << endl;
      }
      void print(double d) {
        cout << "Printing double: " << d << endl;
      }
      void print(string s) {
        cout << "Printing string: " << s << endl;
      }
};

int main(void) {
   printData pd;
 
   pd.print(5);
   pd.print(500.263);
   pd.print("Hello");
 
   return 0;
}
