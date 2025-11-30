#include <iostream>
#include <string>
#include <ctime>
#include "HashTable.h"
using namespace std;


string gen_random(const int len) {
    string tmp_s;
    static const char alphanum[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";

    tmp_s.reserve(len);
    for (int i = 0; i < len; ++i) 
        tmp_s += alphanum[rand() % (sizeof(alphanum) - 1)];
    
    return tmp_s;
}

bool test1(){
    HashTable ab(19);
    string names[8] = {"Alice", "Bob", "Chris", "Denise", "Ellen", "Fred", "George", "Hannah"};
    int hv[19] = {0};
    for(int i=0; i<8; i++){
		if (ab.hashFunction(names[i]) > 18){
			cout << "Out of bounds ";
            return false;
		}
        hv[ab.hashFunction(names[i])] += 1;
    }
    for (int i=0; i<19; i++){
        if (hv[i] > 7){
			cout << "All elements hashed to same value ";
            return false;
        }
    }
    return true;
}

bool test2(){
    HashTable ab(19);
	int t1 = ab.hashFunction("asd123");
    for(int i=0; i<8; i++){
		if(ab.hashFunction("asd123") != t1){
			cout << "Different values for " << "asd123";
            return false;
		}
    }
	HashTable ac(23);
    int t2 = ab.hashFunction("123asd");
    for(int i=0; i<8; i++){
        if(ab.hashFunction("123asd") != t2){
            cout << "Different values for " << "123asd";
            return false;
        }
    }
    return true;
}

bool test3(int thold){
    HashTable ab(19);
    int hv[19] = {0};
	string is = "";
    for(int i=0; i<(19 * 100); i++){
        is = gen_random( (rand() % 8) + 2);
        hv[ab.hashFunction(is)] += 1;
    }
    for (int i=0; i<19; i++){
        // cout << hv[i] << ":";
        if (hv[i] > thold){
            cout << "Poor uniformity ";
            return false;
        }
    }
    return true;
}

bool test6(){
    HashTable ab(19);
    ab.insert("asd", "123");
    if (ab.s2("asd") != ab.hashFunction("asd")){
        cout << "Not inserted at hash value slot ";
        return false;
    }
	HashTable ac(19);
    ac.insert("zxxx", "123");
    if (ac.s2("zxxx") != ac.hashFunction("zxxx")){
        cout << "Not inserted at hash value slot ";
        return false;
    }
    return true;
}

bool test7(){
    string names[8] = {"Alice", "Bob", "Chris", "Denise", "Ellen", "Fred", "George", "Hannah"};
    string exts[8] = {"123", "234", "345", "456", "567", "678", "789", "890"};

    HashTable ab(19);

    for(int i=0; i<8; i++){
        if( ab.insert(exts[i], names[i]) ){
        }else{
            cout << "Failed to insert 8 elements in 19 slot table ";
            return false;
        }
    }
	return true;
}

bool test8(){
    HashTable ab(19);
	ab.insert("abc", "123");

    for(int i=0; i<8; i++){
        if( ab.insert("abc", "456") ){
			cout << "Duplicate key inserted ";
            return false;
        }
    }
    return true;
}

bool test9(){
    string names[20] = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t"};
    string exts[20] = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "0", "11", "12", "13", "14", "15", "16", "17", "18", "19", "20"};

    HashTable ab(15);

	int added = 0;
    for(int i=0; i<20; i++){
        if( ab.insert(exts[i], names[i]) ){
			added += 1;
        }else{
			if(added < 12){
				cout << "Too many unused slots ";
				return false;
			}else{
                cout << "Used " << added << " of 15 slots ";
				break;
			}
        }
    }
    return true;
}

bool test10(){
    string names[8] = {"Alice", "Bob", "Chris", "Denise", "Ellen", "Fred", "George", "Hannah"};
    string exts[8] = {"123", "234", "345", "456", "567", "678", "789", "890"};

    HashTable ab(19);
	string insd = "";

    for(int i=0; i<8; i++){
		if( ab.hashFunction(exts[i]) > 0){
			insd = exts[i];
			ab.insert(exts[i], names[i]);
			ab.i2(exts[i], "NOPE");
			break;
		}
		if(i==7){
			return false;
		}
    }
	int x = ab.search(insd);
	if (x < 1){
		cout << "Incorrect search slot ";
		return false;
	}
    return true;
}

bool test11(){
    string names[8] = {"Alice", "Bob", "Chris", "Denise", "Ellen", "Fred", "George", "Hannah"};
    string exts[8] = {"123", "234", "345", "456", "567", "678", "789", "890"};

    HashTable ab(19);

    for(int i=0; i<8; i++){
        ab.insert(exts[i], names[i]);
    }
    int x = ab.search("Eddy");
    if (x != -1){
        return false;
    }
    return true;
}

bool test12(){
    string names[8] = {"Alice", "Bob", "Chris", "Denise", "Ellen", "Fred", "George", "Hannah"};
    string exts[8] = {"123", "234", "345", "456", "567", "678", "789", "890"};

    HashTable ab(19);
    string insd = "";

    for(int i=0; i<8; i++){
        ab.insert(names[i], exts[i]);
    }
    string x = ab.lookup("Chris");
    if (x != "345"){
        return false;
    }
    return true;
}

bool test13(){
    string names[8] = {"Alice", "Bob", "Chris", "Denise", "Ellen", "Fred", "George", "Hannah"};
    string exts[8] = {"123", "234", "345", "456", "567", "678", "789", "890"};

    HashTable ab(19);
    string insd = "";

    for(int i=0; i<8; i++){
        ab.insert(exts[i], names[i]);
    }
    string x = ab.lookup("Eddy");
    if (x != ""){
        return false;
    }
    return true;
}


int main(int argc, char** argv) {
    string tn = argv[argc-1];

    if(tn == "1" || tn == "0"){
        // cout << "Hash Fn Test (function): ";
        if (!test1()) {
            cout << "FAILED" << endl;
        }else{
            cout << "PASSED" << endl;
        }
    }

	if(tn == "2" || tn == "0"){
        // cout << "Hash Fn Test (deterministic): ";
        if (!test2()) {
            cout << "FAILED" << endl;
        }else{
            cout << "PASSED" << endl;
        }
    }

    if(tn == "3" || tn == "0"){
        // cout << "Hash Fn Test (uniformity 1): ";
        if (!test3(200)) {
            cout << "FAILED" << endl;
        }else{
            cout << "PASSED" << endl;
        }
    }

	if(tn == "4" || tn == "0"){
        // cout << "Hash Fn Test (uniformity 2): ";
        if (!test3(150)) {
            cout << "FAILED" << endl;
        }else{
            cout << "PASSED" << endl;
        }
    }

	if(tn == "5" || tn == "0"){
        // cout << "Hash Fn Test (uniformity 3): ";
        if (!test3(130)) {
            cout << "FAILED" << endl;
        }else{
            cout << "PASSED" << endl;
            
        }
    }

    if(tn == "6" || tn == "0"){
        // cout << "Insert test 1 (correct slot): ";
        if (!test6()) {
            cout << "FAILED" << endl;
        }else{
            cout << "PASSED" << endl;
            
        }
    }

    if(tn == "7" || tn == "0"){
        // cout << "Insert test 2 (basic): ";
        if (!test7()) {
            cout << "FAILED" << endl;
        }else{
            cout << "PASSED" << endl;
            
        }
    }

    if(tn == "8" || tn == "0"){
        // cout << "Insert test 3 (duplicate keys): ";
        if (!test8()) {
            cout << "FAILED" << endl;
        }else{
            cout << "PASSED" << endl;
            
        }
    }

    if(tn == "9" || tn == "0"){
        // cout << "Insert test 4 (full table): ";
        if (!test9()) {
            cout << "FAILED" << endl;
        }else{
            cout << "PASSED" << endl;
            
        }
    }

	if(tn == "10" || tn == "0"){
        // cout << "Search test 1 (correct slot): ";
        if (!test10()) {
            cout << "FAILED" << endl;
        }else{
            cout << "PASSED" << endl;
            
        }
    }

    if(tn == "11" || tn == "0"){
        // cout << "Search test 2 (item does not exist): ";
        if (!test11()) {
            cout << "FAILED" << endl;
        }else{
            cout << "PASSED" << endl;
            
        }
    }	

    if(tn == "12" || tn == "0"){
        // cout << "Lookup test 1 (basic lookup): ";
        if (!test12()) {
            cout << "FAILED" << endl;
        }else{
            cout << "PASSED" << endl;
            
        }
    }

    if(tn == "13" || tn == "0"){
        // cout << "Lookup test 2 (item does not exist): ";
        if (!test13()) {
            cout << "FAILED" << endl;
        }else{
            cout << "PASSED" << endl;
            
        }
    }

	return 0;
}

