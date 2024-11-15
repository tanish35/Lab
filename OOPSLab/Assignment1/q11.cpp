#include <bits/stdc++.h>
#define ll long long
#define vll vector<long long>
#define db double
#define vi vector<int>
using namespace std;

void Strcpy(const string &s1, string &s2)
{
    s2 = s1;
}

int main()
{
    string s1, s2;
    cout << "Enter a string: ";
    cin >> s1;
    Strcpy(s1, s2);
    cout << "Copied string: " << s2 << endl;
    return 0;
}