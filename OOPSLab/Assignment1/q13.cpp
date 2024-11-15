#include <bits/stdc++.h>
#define ll long long
#define vll vector<long long>
#define db double
#define vi vector<int>
using namespace std;

void maxElement(vi arr)
{
    int max = INT_MIN;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    cout << "Max element: " << max << endl;
}

void maxElement(int a, int b, int c)
{
    int max = INT_MIN;
    if (a > max)
    {
        max = a;
    }
    if (b > max)
    {
        max = b;
    }
    if (c > max)
    {
        max = c;
    }
    cout << "Max element: " << max << endl;
}

int main()
{
    vi arr = {1, 2, 3, 4, 5};
    maxElement(arr);
    maxElement(1, 2, 3);

    return 0;
}