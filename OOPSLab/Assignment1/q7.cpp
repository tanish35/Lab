#include <bits/stdc++.h>
#define ll long long
#define vll vector<long long>
#define db double
#define vi vector<int>
using namespace std;

ll factorial(const ll &n)
{
    if (n == 0)
        return 1;
    return n * factorial(n - 1);
}

int main()
{
    ll n;
    cout << "Enter the number: ";
    cin >> n;
    cout << "Factorial of " << n << " is " << factorial(n) << endl;

    return 0;
}