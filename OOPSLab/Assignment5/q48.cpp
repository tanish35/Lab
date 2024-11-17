#include <bits/stdc++.h>
#define ll long long
#define vll vector<long long>
#define db double
#define vi vector<int>
using namespace std;

class Motor
{
public:
    Motor()
    {
        throw runtime_error("Motor failure");
    }
};

class Car
{
public:
    Motor motor;
    Car()
    try : motor()
    {
    }
    catch (const runtime_error &e)
    {
        cout << "Caught exception in Car constructor: " << e.what() << endl;
        throw;
    }
};

class Garage
{
public:
    Car car;
    Garage()
    try : car()
    {
    }
    catch (const runtime_error &e)
    {
        cout << "Caught exception in Garage constructor: " << e.what() << endl;
        throw logic_error("Garage initialization failed due to car motor issue");
    }
};

int main()
{
    try
    {
        Garage garage;
    }
    catch (const logic_error &e)
    {
        cout << "Caught exception in main: " << e.what() << endl;
    }
}