#include <iostream>
using namespace std;

int main () {
    try {
        throw 10;
    } catch (int e) {
        cerr << "An exception occurred: #" << e << endl;
    }
    return 0;
}
