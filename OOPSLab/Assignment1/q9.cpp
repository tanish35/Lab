#include <bits/stdc++.h>
using namespace std;

void swapString(char a[], char b[])
{
    char temp[100];

    for (int i = 0; a[i] != '\0'; i++)
    {
        temp[i] = a[i];
    }
    temp[strlen(a)] = '\0';

    for (int i = 0; b[i] != '\0'; i++)
    {
        a[i] = b[i];
    }
    a[strlen(b)] = '\0';

    for (int i = 0; temp[i] != '\0'; i++)
    {
        b[i] = temp[i];
    }
    b[strlen(temp)] = '\0';
}

int main()
{
    char a[100], b[100];
    cout << "Enter two strings: ";
    cin >> a >> b;
    cout << "Before swapping: a = " << a << ", b = " << b << endl;
    swapString(a, b);
    cout << "After swapping: a = " << a << ", b = " << b << endl;

    return 0;
}
