#include <iostream>
using namespace std;

class Shape2D
{
public:
    virtual void area() = 0;
    virtual void perimeter() = 0;
};

class Circle : public Shape2D
{
    int radius;

public:
    Circle(int radius)
    {
        this->radius = radius;
    }
    void area()
    {
        cout << "Area of Circle: " << 3.14 * radius * radius << endl;
    }
    void perimeter()
    {
        cout << "Perimeter of Circle: " << 2 * 3.14 * radius << endl;
    }
};

class Rectangle : public Shape2D
{
    int length, breadth;

public:
    Rectangle(int length, int breadth)
    {
        this->length = length;
        this->breadth = breadth;
    }
    void area()
    {
        cout << "Area of Rectangle: " << length * breadth << endl;
    }
    void perimeter()
    {
        cout << "Perimeter of Rectangle: " << 2 * (length + breadth) << endl;
    }
};

int main()
{
    Shape2D *s[5];
    s[0] = new Circle(5);
    s[1] = new Rectangle(5, 10);
    s[2] = new Circle(10);
    s[3] = new Rectangle(10, 20);
    s[4] = new Circle(20);

    for (int i = 0; i < 5; i++)
    {
        s[i]->area();
        s[i]->perimeter();
    }

    return 0;
}