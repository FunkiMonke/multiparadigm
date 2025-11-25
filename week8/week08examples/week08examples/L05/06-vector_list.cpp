#include <iostream>
#include <string>
#include <vector>
using namespace std;
 
class Studentlist {
    private:
        vector <string> students;
    public:
        Studentlist(){
        }
        void add_student(string s);
        void print_list();
};
 
void Studentlist::add_student(string s){
    students.push_back(s);
}

void Studentlist::print_list(){
    for (int i=0; i<students.size(); i++){
        cout << students.at(i) << endl;
    }
}

int main() {
   Studentlist students;
   students.add_student("Fred");
   students.add_student("Wilma");
   students.print_list();

   return 0;
}
