#include <iostream>
#include <exception>
#include <vector>
using namespace std;

double divide(int a, int b) {
   if( b == 0 ) {
      throw "Division by zero";
   }
   return (a/b);
}

int main() {
    int myval = 0;
    double result = 0;
    vector<int> myvector(10, 1);

    try {
        myval = myvector.at(30);
        result = divide(myval, 0);
        cout << "Result: " << result << endl;
        throw 10;
    } catch (const out_of_range& oor) {
        cout << "Out of Range error" << endl;
    } catch (const char* msg) {
        cout << msg << endl;
    } catch (...) {
        cout << "Misc exception" << endl;
    }

    return 0;
}
