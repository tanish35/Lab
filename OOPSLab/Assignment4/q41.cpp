#include <bits/stdc++.h>
#define ll long long
#define vll vector<long long>
#define db double
#define vi vector<int>
using namespace std;

class Integer
{
    int i;

public:
    Integer(int i = 0) : i(i) {}
    Integer(const Integer &i) : i(i.i) {}
    Integer operator++(int)
    {
        Integer temp = *this;
        i++;
        return temp;
    }
    Integer operator+(Integer &i)
    {
        return this->i + i.i;
    }
    operator int()
    {
        return i;
    }
    friend ostream &operator<<(ostream &out, Integer &i)
    {
        out << i.i;
        return out;
    }
};

int main()
{
    Integer a = 4, b = a, c;
    c = a + b++;
    int i = a;
    cout << a << b << c;
    return 0;
}