#include <bits/stdc++.h>
#define ll long long
#define vll vector<long long>
#define db double
#define vi vector<int>
using namespace std;

class Index
{
    int i;

public:
    Index(int x) : i(x) {}
    operator int() { return i; }
    Index operator+(Index &x)
    {
        return Index(i + x.i);
    }
    Index operator=(int x)
    {
        i = x;
        return *this;
    }
    operator Integer(){};
};

class Integer
{
    int i;

public:
    Integer(int x = 0) : i(x) {}
    operator int() { return i; }
    Integer(Integer &x)
    {
        i = x.i;
    }
};

Index::operator Integer()
{
    return Integer(i);
}

int main()
{
    Index in(4), out(10);
    int x = in;
    int y = in + out;
    in = 2;
    Integer i;
    i = in;
    return 0;
}