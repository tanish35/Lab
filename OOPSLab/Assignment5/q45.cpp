#include <bits/stdc++.h>
#define ll long long
#define vll vector<long long>
#define db double
#define vi vector<int>
using namespace std;

int main()
{
    int a;
    try
    {
        cout << "Enter a number: ";
        cin >> a;

        if (a < 0)
        {
            throw a;
        }
        else if (a == 0)
        {
            throw string("Zero is not allowed");
        }
        else
        {
            cout << "You entered: " << a << endl;
        }
    }
    catch (int e)
    {
        cout << "Caught an integer exception: " << e << endl;
    }
    catch (string &e)
    {
        cout << "Caught a string exception: " << e << endl;
    }

    return 0;
}