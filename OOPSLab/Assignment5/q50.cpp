#include <bits/stdc++.h>
#define ll long long
#define vll vector<long long>
#define db double
#define vi vector<int>
using namespace std;

class Complex
{
private:
    double real;
    double imag;

public:
    Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}

    double getReal() const { return real; }
    double getImag() const { return imag; }
    double magnitude() const { return sqrt(real * real + imag * imag); }

    bool operator>(const Complex &other) const
    {
        return this->magnitude() > other.magnitude();
    }

    friend ostream &operator<<(ostream &os, const Complex &c)
    {
        os << c.real << "+" << c.imag << "i";
        return os;
    }
};

template <typename T>
T customMax(T a, T b)
{
    return (a > b) ? a : b;
}

template <>
const char *customMax<const char *>(const char *a, const char *b)
{
    return (strcmp(a, b) > 0) ? a : b;
}

int main()
{
    int int1 = 10, int2 = 20;
    cout << "Maximum of " << int1 << " and " << int2 << " is " << customMax(int1, int2) << endl;

    Complex complex1(3.0, 4.0), complex2(1.0, 7.0);
    cout << "Maximum of " << complex1 << " and " << complex2 << " is " << customMax(complex1, complex2) << endl;

    const char *str1 = "apple";
    const char *str2 = "banana";
    cout << "Maximum of \"" << str1 << "\" and \"" << str2 << "\" is \"" << customMax(str1, str2) << "\"" << endl;

    return 0;
}
