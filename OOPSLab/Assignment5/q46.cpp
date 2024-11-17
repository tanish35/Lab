#include <bits/stdc++.h>
#define ll long long
#define vll vector<long long>
#define db double
#define vi vector<int>
using namespace std;

class MyClass
{
public:
    class Exception
    {
        const char *description;
    public:
        Exception(const char *desc) : description(desc) {}
        const char *what() const { return description; }
    };

    void throwException()
    {
        throw Exception("An error occurred in MyClass");
    }
};

int main()
{
    MyClass obj;
    try
    {
        obj.throwException();
    }
    catch (const MyClass::Exception &e)
    {
        cout << "Caught exception: " << e.what() << endl;
    }

    return 0;
}
