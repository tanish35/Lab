#include <bits/stdc++.h>
using namespace std;

class Rectangle
{
public:
    int length, breadth;
    Rectangle(int length, int breadth)
    {
        this->length = length;
        this->breadth = breadth;
    }

    void calculateArea()
    {
        cout << "Area of the rectangle is: " << length * breadth << endl;
    }
};

int main()
{
    Rectangle r1(5, 10);
    Rectangle r2(10, 20);
    Rectangle r3(20, 30);
    Rectangle r4(30, 40);
    r1.calculateArea();
    r2.calculateArea();
    r3.calculateArea();
    r4.calculateArea();
    return 0;
}