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
    void display()
    {
        cout << real << " + " << imag << "i" << endl;
    }
};

class Quadratic
{
    int a, b, c;

public:
    Quadratic(int a, int b, int c) : a(a), b(b), c(c) {}
    ~Quadratic() {}
    Quadratic() : a(0), b(0), c(0) {}
    Quadratic operator+(Quadratic &q)
    {
        return Quadratic(a + q.a, b + q.b, c + q.c);
    }
    friend ostream &operator<<(ostream &out, const Quadratic &q)
    {
        out << q.a << "x^2 + " << q.b << "x + " << q.c << endl;
        return out;
    }
    friend istream &operator>>(istream &in, Quadratic &q)
    {
        in >> q.a >> q.b >> q.c;
        return in;
    }
    long long eval(int x)
    {
        return a * x * x + b * x + c;
    }
    void roots()
    {
        int d = b * b - 4 * a * c;
        if (d < 0)
        {
            Complex c1(-b / (2 * a), sqrt(-d) / (2 * a)), c2(-b / (2 * a), -sqrt(-d) / (2 * a));
            cout << "Roots: ";
            c1.display();
            c2.display();
            return;
        }
        cout << "Roots: " << (-b + sqrt(d)) / (2 * a) << ", " << (-b - sqrt(d)) / (2 * a) << endl;
    }
};

int main()
{
    Quadratic q1(1, 1, 1), q2(2, 2, 2), q3;

    return 0;
}