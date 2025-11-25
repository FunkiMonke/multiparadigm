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

        bool operator<(const Rectangle& r) {
            double area1 = width * height;
            double area2 = r.width * r.height;
            if(area1 < area2){
                return true;
            }
            return false;
        }
};
 
int main() {
    Rectangle r1(1.0, 5.0);
    Rectangle r2(1.0, 2.0);

    if(r1 < r2){
        cout << "r1 is smaller" << endl;
    }else if (r2 < r1){
        cout << "r2 is smaller" << endl;
    }else{
        cout << "r1 and r2 are the same area" << endl;
    }

    return 0;
}
