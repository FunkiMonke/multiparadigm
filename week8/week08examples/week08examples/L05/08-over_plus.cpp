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

        Rectangle operator+(const Rectangle& r) {
            Rectangle rect;
            rect.width = this->width + r.width;
            rect.height = this->height + r.height;
            return rect;
        }
};
 
int main() {
    Rectangle r1(2.0, 1.0);
    Rectangle r2(1.0, 2.0);

    Rectangle r3 = r1 + r2;

    r1.print_rectangle();
    r2.print_rectangle();
    r3.print_rectangle();
    return 0;
}
