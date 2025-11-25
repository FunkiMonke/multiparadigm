#include <iostream>
using namespace std;

#define PI 3.14159265
 
class Shape {
    protected:
        double width;
        double height;
    public:
        virtual double area(){
            return 0.0;
        }
};
 
class Rectangle: public Shape {
    public:
        Rectangle(double w, double h){
            width = w;
            height = h;
        }
        double area(){
            return width * height;
        }
};

class Triangle: public Shape {
    public:
        Triangle(double w, double h){
            width = w;
            height = h;
        }
        double area(){
            return (width * height) / 2;
        }
};

class Circle: public Shape {
    public:
        Circle(double w){
            width = w;
            height = w;
        }
        double area(){
            return PI * (width / 2) * (width / 2);
        }
};

double total_area(Shape &s1, Shape &s2){
    return s1.area() + s2.area();
}

int main() {
    Rectangle r(1,1);
    Triangle t(1,1);
    Circle c(1);

    cout << "Total area: " << total_area(r,t) << endl;
 
    return 0;
}
