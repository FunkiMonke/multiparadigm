#include <iostream>
using namespace std;
 
class Rectangle {
    private:
        double width;
        double height;
    public:
        Rectangle(int w=0.0, int h=0.0){
            width = w;
            height = h;
        }
        double get_width(){
            return width;
        }
        double get_height(){
            return height;
        }
        double get_area(){
            return width * height;
        }
        void print_rectangle(){
            cout << width << "x" << height <<
                " rectangle. Area = " << this->get_area() << endl;
        }

        Rectangle& operator++(){        // prefix ++R
            width += 1;
            height += 1;
            return *this;
        }

        Rectangle operator++(int){      // postfix R++
            Rectangle r(width,height);  // make a copy for result
            width += 1;
            height += 1;
            return r;                   // return the copy (the old) value.
        }
};
 
int main() {
    Rectangle r1(2.0, 1.0);
    r1.print_rectangle();
    r1++;
    r1.print_rectangle();

    Rectangle r2;
    r2 = r1++;
    r1.print_rectangle();
    r2.print_rectangle();

    return 0;
}
