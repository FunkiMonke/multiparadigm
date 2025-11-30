#include "myvectortemplate.h"
#include<iostream>
using namespace std;

int main() {
	MyVector<int> v;
	v.push_back(5);
    v.push_back(4);
    v.push_back(3);
	cout << "The vector elements are: ";
	for (int i = 0; i < v.size(); i++){
		cout << v.at(i) << " ";
	}
	cout << endl;

    int j = v.pop_back();
    cout << "Removed " << j << ". Now the vector elements are: ";
	cout << v << endl;
    cout << "Front element is " << v.front() << " back element is " << v.back() << endl;
    cout << endl;

    MyVector<char> w;
    w.assign(4, 'a');
    w.push_back('b');
	cout << "The vector elements are: ";
    cout << w << endl;

	return 0;
}
