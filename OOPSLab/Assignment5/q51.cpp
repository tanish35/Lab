#include <bits/stdc++.h>
using namespace std;

template <typename T>
void swapValues(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

class Complex
{
private:
    double real;
    double imag;

public:
    Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}

    double getReal() const { return real; }
    double getImag() const { return imag; }

    friend ostream &operator<<(ostream &os, const Complex &c)
    {
        os << c.real << "+" << c.imag << "i";
        return os;
    }
};

template <typename T>
class Stack
{
private:
    vector<T> elements;

public:
    void push(T value) { elements.push_back(value); }
    void pop()
    {
        if (!elements.empty())
            elements.pop_back();
    }
    T top() const { return elements.back(); }
    bool empty() const { return elements.empty(); }

    friend ostream &operator<<(ostream &os, const Stack<T> &stack)
    {
        for (const T &el : stack.elements)
            os << el << " ";
        return os;
    }
};

template <typename T>
void swapValues(Stack<T> &stack1, Stack<T> &stack2)
{
    Stack<T> temp = stack1;
    stack1 = stack2;
    stack2 = temp;
}

int main()
{

    int a = 10, b = 20;
    cout << "Before swapping: a = " << a << ", b = " << b << endl;
    swapValues(a, b);
    cout << "After swapping: a = " << a << ", b = " << b << endl;

    Complex c1(3, 4), c2(1, 7);
    cout << "\nBefore swapping: c1 = " << c1 << ", c2 = " << c2 << endl;
    swapValues(c1, c2);
    cout << "After swapping: c1 = " << c1 << ", c2 = " << c2 << endl;

    Stack<int> stack1, stack2;
    stack1.push(1);
    stack1.push(2);
    stack1.push(3);
    stack2.push(10);
    stack2.push(20);
    stack2.push(30);

    cout << "\nBefore swapping:\nStack1: " << stack1 << "\nStack2: " << stack2 << endl;
    swapValues(stack1, stack2);
    cout << "After swapping:\nStack1: " << stack1 << "\nStack2: " << stack2 << endl;

    return 0;
}
