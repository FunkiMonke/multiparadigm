#include <iostream>
#include <string>
using namespace std;
 
class Studentlist {
    private:
        string students[100];
        int next_index;
    public:
        Studentlist(){
            next_index = 0;
        }
        void add_student(string s);
        void print_list();
};
 
void Studentlist::add_student(string s){
    students[next_index] = s;
    next_index++;
}

void Studentlist::print_list(){
    for (int i=0; i<100; i++){
        if(students[i] != ""){
            cout << students[i] << endl;
        }
    }
}

int main() {
   Studentlist students;
   students.add_student("Fred");
   students.add_student("Wilma");
   students.print_list();

   return 0;
}
