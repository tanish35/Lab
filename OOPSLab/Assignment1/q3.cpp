#include <bits/stdc++.h>
#define ll long long
#define vll vector<long long>
#define db double
#define vi vector<int>
using namespace std;

int main()
{
    int x = 1;
    for (int i = 1; i <= 6; i++)
    {
        x *= i;
        cout << i << "! = " << x << endl;
    }
    return 0;
}