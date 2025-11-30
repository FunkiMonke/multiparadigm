#include <iostream>
#include <exception>
#include <vector>
using namespace std;

int main() {
    vector<int> myvector(10);
    try {
        myvector.at(2)=1;
    }
    catch (const std::out_of_range& oor) {
        cout << "Out of Range error" << endl;
    }
    return 0;
}
