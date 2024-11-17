#include <bits/stdc++.h>
#define ll long long
#define vll vector<long long>
#define db double
#define vi vector<int>
using namespace std;

int main()
{
    int a, b;
    cout << "Enter two numbers: ";
    cin >> a >> b;
    try
    {
        if (b == 0)
        {
            throw string("Division by zero is not allowed");
        }
        cout << "Division: " << a / b << endl;
    }
    catch (const string &msg)
    {
        cout << "Error: " << msg << endl;
    }
    return 0;
}