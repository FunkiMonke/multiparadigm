
#include <iostream>
#include <string>
using namespace std;
class Time
{
    private:
    int hour;
    int minute;
    int second;

    public:
    Time(int h = 0, int m = 0, int s = 0)
    {
        hour = h;
        minute = m;
        second = s;
    }

    friend ostream& operator<<(ostream &output, const Time &t)
    {
        output << t.hour << ":" << t.minute << ":" << t.second;
        return output;
    }

    Time& operator++()
    {
        second+=1;
        return *this;
    }

    Time operator++(int i)
    {
        Time y(hour, minute, second);
        second += 1;
        return y;
    }

    void setTime(int h, int m, int s)
    {
        hour = h;
        minute = m;
        second = s;
    }

};

int main() 
{
    Time t(2,5,8);
    cout << t <<endl;
    t++;
    cout << t <<endl;
    ++t;
    cout << t <<endl;
    return 0;
}

