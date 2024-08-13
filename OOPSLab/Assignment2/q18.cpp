#include <bits/stdc++.h>
using namespace std;

class Point
{
public:
    int x, y;

    Point() : x(0), y(0) {}

    Point(int x, int y)
    {
        this->x = x;
        this->y = y;
    }

    double distanceTo(const Point &other) const
    {
        return sqrt(pow(x - other.x, 2) + pow(y - other.y, 2));
    }
};

class WirelessDevice
{
private:
    static int idCounter;
    int id;
    Point location;
    double transmissionRange;

public:
    WirelessDevice(int x, int y, double transmissionRange)
    {
        id = rand() % 1000;
        location = Point(x, y);
        this->transmissionRange = transmissionRange;
    }
    int getId() const
    {
        return id;
    }

    Point getLocation() const
    {
        return location;
    }

    void setLocation(int x, int y)
    {
        location = Point(x, y);
    }

    bool isInRange(const WirelessDevice &other) const
    {
        return location.distanceTo(other.getLocation()) <= transmissionRange;
    }
};

void findNeighbors(const vector<WirelessDevice> &devices)
{
    for (const auto &device : devices)
    {
        cout << "Device " << device.getId() << " neighbors: ";
        for (const auto &other : devices)
        {
            if (device.getId() != other.getId() && device.isInRange(other))
            {
                cout << other.getId() << " ";
            }
        }
        cout << endl;
    }
}

int main()
{
    srand(time(0));
    vector<WirelessDevice> devices;

    srand(time(0));

    for (int i = 0; i < 10; ++i)
    {
        int x = rand() % 100;
        int y = rand() % 100;
        double range = (rand() % 50) + 10;
        devices.push_back(WirelessDevice(x, y, range));
    }

    cout << "Initial neighbors:" << endl;
    findNeighbors(devices);

    for (auto &device : devices)
    {
        int newX = rand() % 100;
        int newY = rand() % 100;
        device.setLocation(newX, newY);
    }

    cout << "New neighbors after moving:" << endl;
    findNeighbors(devices);

    return 0;
}