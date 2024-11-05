#include <bits/stdc++.h>
#define ll long long
#define vll vector<long long>
#define db double
#define vi vector<int>
using namespace std;

class INT
{
    int i;

public:
    INT(int a) : i(a) {}
    ~INT() {}
    INT &operator++()
    {
        i++;
        return *this;
    }
    INT operator++(int)
    {
        INT temp = *this;
        i++;
        return temp;
    }
    INT operator=(INT a)
    {
        i = a.i;
        return *this;
    }
    operator int()
    {
        return i;
    }
    void display()
    {
        cout << i << endl;
    }
};

int main()
{
    int x = 3;
    INT y = x;
    y++ = ++y;
    x = y;
    cout << x << endl;
    y.display();

    return 0;
}
