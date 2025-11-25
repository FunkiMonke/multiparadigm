#include<iostream>
#include "Complex.h"
using namespace std;

void Complex::set_real(double r){
    real = r;
}
double Complex::get_real(){
    return real;
}
void Complex::set_img(double i){
    img = i;
}
double Complex::get_img(){
    return img;
}

Complex::Complex() {
    real = 0;
    img = 0;
}

Complex::Complex(double r, double i) {
    real = r;
    img = i;
}

ostream& operator<<(ostream &output, const Complex &c) {
    output<<c.real<<c.img;
}

Complex Complex::operator+(const Complex& c) {
    Complex t;
    t.real += c.real;
    
    
}
