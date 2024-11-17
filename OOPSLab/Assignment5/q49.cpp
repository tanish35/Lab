#include <bits/stdc++.h>
#define ll long long
#define vll vector<long long>
#define db double
#define vi vector<int>
using namespace std;

class Vehicle
{
public:
    enum Direction
    {
        STOPPED,
        FORWARD,
        BACKWARD
    };
    Direction direction;

    Vehicle(Direction dir) : direction(dir) {}
};

class Lane
{
public:
    void checkForCollision(const Vehicle &v1, const Vehicle &v2)
    {
        if (v1.direction == Vehicle::FORWARD && v2.direction == Vehicle::BACKWARD)
        {
            throw runtime_error("Collision detected: Vehicles are running in opposite directions!");
        }
        if (v1.direction == Vehicle::BACKWARD && v2.direction == Vehicle::FORWARD)
        {
            throw runtime_error("Collision detected: Vehicles are running in opposite directions!");
        }
    }
};

int main()
{
    try
    {
        Vehicle car1(Vehicle::FORWARD);
        Vehicle car2(Vehicle::BACKWARD);

        Lane lane;
        lane.checkForCollision(car1, car2);

        cout << "No collision detected. Vehicles are safe." << endl;
    }
    catch (const runtime_error &e)
    {
        cout << "Exception: " << e.what() << endl;
    }
    return 0;
}