#include <iostream>
using namespace std;

#define db double

class Complex
{
private:
    db real;
    db imaginary;

public:
    Complex(db real, db imaginary)
    {
        this->real = real;
        this->imaginary = imaginary;
    }

    void setReal(db real)
    {
        this->real = real;
    }
    db getReal()
    {
        return real;
    }
    void setImaginary(db imaginary)
    {
        this->imaginary = imaginary;
    }
    db getImaginary()
    {
        return imaginary;
    }
    void display()
    {
        cout << real << "+" << imaginary << "i" << endl;
    }
    Complex add(Complex &c)
    {
        Complex temp(real + c.real, imaginary + c.imaginary);
        return temp;
    }
};

int main()
{
    Complex c1(3, 4), c2(5, 6);
    Complex c3 = c1.add(c2);
    c3.display();
    return 0;
}