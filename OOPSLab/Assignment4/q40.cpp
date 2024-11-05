#include <bits/stdc++.h>
#define ll long long
#define vll vector<long long>
#define db double
#define vi vector<int>
using namespace std;

class IntArray
{
    int *arr;
    int size;

public:
    IntArray(int s)
    {
        size = s;
        arr = new int[size];
    }
    int &operator[](int i)
    {
        return arr[i];
    }
    friend ostream &operator<<(ostream &out, IntArray &i)
    {
        for (int k = 0; k < i.size; k++)
            out << i.arr[k] << " ";
        out << endl;
        return out;
    }
};

int main()
{
    IntArray i(10);
    for (int k = 0; k < 10; k++)
        i[k] = k;
    cout << i;
    return 0;
}