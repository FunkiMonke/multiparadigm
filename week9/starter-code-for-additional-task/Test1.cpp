#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include "HashNode.h"
using namespace std;


bool test1(){
	HashNode hn;
	string k = hn.getKey();
	string v = hn.getValue();
    if(k != ""){
		cout << "Key not set to empty string ";
		return false;
	}
    if(v != ""){
        cout << "Value not set to empty string ";
        return false;
    }
	return true;
}

bool test2(string ik, string iv){
    HashNode hn(ik, iv);
    string k = hn.getKey();
    string v = hn.getValue();
    if(k != ik){
        cout << "Key not set correctly (" << ik << ") ";
        return false;
    }
    if(v != iv){
        cout << "Value not set correctly (" << iv << ") ";
        return false;
    }
    return true;
}

bool test3(string ik, string iv, string sv){
    HashNode hn(ik, iv);
    string k = hn.getKey();
	hn.setValue(sv);
    string v = hn.getValue();
    if(k != ik){
        cout << "Key not set correctly (" << ik << ") ";
        return false;
    }
    if(v != sv){
        cout << "Value not updated correctly (" << sv << ") ";
        return false;
    }
    return true;
}

bool test4(string ik, string iv, bool printit=true) {
	string target = ik + ":" + iv;
	HashNode hn(ik, iv);
    stringstream buffer;
    streambuf * old = cout.rdbuf(buffer.rdbuf());
    cout << hn;
    string test = buffer.str();
    cout.rdbuf(old);
    test.erase(remove(test.begin(), test.end(), '\n'), test.end());
    if(printit){
        cout << "[EXPECTED: " << target << " GOT: " << test << "] ";
    }
    if (test != target){
        return false;
    }
    return true;
}
	

int main(int argc, char** argv) {
    
    string tn = argv[argc-1];

    if(tn == "1"){
        // cout << "Default constructor test: ";
        if (!test1()) {
            cout << "FAILED" << endl;
        }else{
            cout << "PASSED" << endl;
            
        }
    }

    if(tn == "2"){
        // cout << "Parametrized constructor test: ";
        if (!test2("abc", "def")) {
            cout << "FAILED" << endl;
        }else{
            cout << "PASSED" << endl;
            
        }
    }

    if(tn == "3"){
        // cout << "SetValue test: ";
        if (!test3("abc", "def", "ghi")) {
            cout << "FAILED" << endl;
        }else{
            cout << "PASSED" << endl;
            
        }
    }

    if(tn == "4"){
        // cout << "Output test: ";
        if (!test4("abc", "def", true)) {
            cout << "FAILED" << endl;
        }else{
            cout << "PASSED" << endl;
            
        }
    }

	return 0;
}
