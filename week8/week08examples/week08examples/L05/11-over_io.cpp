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

        friend ostream & operator<<(ostream &output, const Rectangle &r) {
            output << r.width << "x" << r.height << " rectangle";
            return output;
        }

        friend istream & operator>>(istream &input,  Rectangle &r) {
            cout << "Enter width: ";
            input >> r.width;
            cout << "Enter height: ";
            input >> r.height;
            return input;
        }
};
 
int main() {
    Rectangle r(2.0, 1.0);
    cout << r << endl;

    cin >> r;
    cout << r << endl;

    return 0;
}
