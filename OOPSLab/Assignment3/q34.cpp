#include <iostream>
#include <vector>
using namespace std;

class Shape
{
public:
    virtual int is3D() = 0;
};

class Shape2D : public Shape
{
public:
    virtual void area() = 0;
    int is3D()
    {
        return 0;
    }
};

class Shape3D : public Shape
{
public:
    int is3D()
    {
        return 1;
    }
    virtual void volume() = 0;
    virtual void area() = 0;
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
};

class Triangle : public Shape2D
{
    int a, b, c;

public:
    Triangle(int a, int b, int c)
    {
        this->a = a;
        this->b = b;
        this->c = c;
    }
    void area()
    {
        int s = (a + b + c) / 2;
        cout << "Area of Triangle: " << sqrt(s * (s - a) * (s - b) * (s - c)) << endl;
    }
};

class Ellipse : public Shape2D
{
    int major, minor;

public:
    Ellipse(int major, int minor)
    {
        this->major = major;
        this->minor = minor;
    }
    void area()
    {
        cout << "Area of Ellipse: " << 3.14 * major * minor << endl;
    }
};

class Sphere : public Shape3D
{
    int radius;

public:
    Sphere(int radius)
    {
        this->radius = radius;
    }
    void area()
    {
        cout << "Area of Sphere: " << 4 * 3.14 * radius * radius << endl;
    }
    void volume()
    {
        cout << "Volume of Sphere: " << 4 / 3 * 3.14 * radius * radius * radius << endl;
    }
};

class Cube : public Shape3D
{
    int side;

public:
    Cube(int side)
    {
        this->side = side;
    }
    void area()
    {
        cout << "Area of Cube: " << 6 * side * side << endl;
    }
    void volume()
    {
        cout << "Volume of Cube: " << side * side * side << endl;
    }
};

int main()
{
    vector<Shape *> s;
    s.push_back(new Circle(5));
    s.push_back(new Triangle(3, 4, 5));
    s.push_back(new Ellipse(5, 10));
    s.push_back(new Sphere(5));
    s.push_back(new Cube(5));

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i]->is3D())
        {
            ((Shape3D *)s[i])->area();
            ((Shape3D *)s[i])->volume();
        }
        else
        {
            ((Shape2D *)s[i])->area();
        }
    }

    return 0;
}