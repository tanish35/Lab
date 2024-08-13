#include <bits/stdc++.h>
using namespace std;

class GeometricalPoint
{
public:
    int x, y, z;
    GeometricalPoint(int x, int y, int z)
    {
        this->x = x;
        this->y = y;
        this->z = z;
    }

    void calculateDistance(GeometricalPoint q)
    {
        double distance = sqrt(pow(x - q.x, 2) + pow(y - q.y, 2) + pow(z - q.z, 2));
        cout << "Distance between the points is: " << distance << endl;
    }
};

int main()
{
    GeometricalPoint p(1, 2, 3);
    GeometricalPoint q(4, 5, 6);
    p.calculateDistance(q);
    return 0;
}