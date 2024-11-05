#include <bits/stdc++.h>
#define ll long long
#define vll vector<long long>
#define db double
#define vi vector<int>
using namespace std;

class Point
{
    double x, y;

public:
    Point(double x, double y) : x(x), y(y) {}
    ~Point() {}

    double operator-(Point &p)
    {
        return sqrt(pow(x - p.x, 2) + pow(y - p.y, 2));
    }
};

int main()
{
    Point p1(1, 1), p2(2, 2);
    cout << "Distance between p1 and p2: " << p1 - p2 << endl;

    return 0;
}