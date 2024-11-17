#include <bits/stdc++.h>
#define ll long long
#define vll vector<long long>
#define db double
#define vi vector<int>
using namespace std;

template <typename T>
class Stack
{
private:
    vector<T> elements;

public:
    void push(T value)
    {
        elements.push_back(value);
    }

    void pop()
    {
        if (!elements.empty())
            elements.pop_back();
        else
            cout << "Stack is empty, cannot pop." << endl;
    }

    T top() const
    {
        if (!elements.empty())
            return elements.back();
        throw runtime_error("Stack is empty, no top element.");
    }

    bool empty() const
    {
        return elements.empty();
    }

    void print() const
    {
        if (elements.empty())
        {
            cout << "Stack is empty." << endl;
        }
        else
        {
            cout << "Stack elements: ";
            for (const T &el : elements)
            {
                cout << el << " ";
            }
            cout << endl;
        }
    }
};

class Complex
{
private:
    double real;
    double imag;

public:
    Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}

    friend ostream &operator<<(ostream &os, const Complex &c)
    {
        os << c.real << "+" << c.imag << "i";
        return os;
    }
};

int main()
{
    Stack<int> intStack;
    intStack.push(10);
    intStack.push(20);
    intStack.push(30);

    cout << "Integer Stack after pushes:" << endl;
    intStack.print();

    intStack.pop();
    cout << "Integer Stack after one pop:" << endl;
    intStack.print();

    Stack<Complex> complexStack;
    complexStack.push(Complex(3, 4));
    complexStack.push(Complex(1, 7));
    complexStack.push(Complex(2, 5));

    cout << "Complex Number Stack after pushes:" << endl;
    complexStack.print();

    complexStack.pop();
    cout << "Complex Number Stack after one pop:" << endl;
    complexStack.print();

    return 0;
}
