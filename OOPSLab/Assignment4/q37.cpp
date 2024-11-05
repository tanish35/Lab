#include <bits/stdc++.h>
#define ll long long
#define vll vector<long long>
#define db double
#define vi vector<int>
using namespace std;

class Complex
{
    double real, imag;

public:
    Complex(double real, double imag) : real(real), imag(imag) {}
    ~Complex() {}
    Complex operator-(Complex &c)
    {
        return Complex(real - c.real, imag - c.imag);
    }
    Complex operator+(Complex &c)
    {
        return Complex(real + c.real, imag + c.imag);
    }
    Complex operator*(Complex &c)
    {
        return Complex(real * c.real - imag * c.imag, real * c.imag + imag * c.real);
    }
    Complex operator/(Complex &c)
    {
        return Complex((real * c.real + imag * c.imag) / (c.real * c.real + c.imag * c.imag), (imag * c.real - real * c.imag) / (c.real * c.real + c.imag * c.imag));
    }
    void display()
    {
        cout << real << " + " << imag << "i" << endl;
    }
};

int main()
{
    Complex c1(1, 1), c2(2, 2);
    cout << "c1 - c2: ";
    (c1 - c2).display();
    cout << "c1 + c2: ";
    (c1 + c2).display();
    cout << "c1 * c2: ";
    (c1 * c2).display();
    cout << "c1 / c2: ";
    (c1 / c2).display();

    return 0;
}