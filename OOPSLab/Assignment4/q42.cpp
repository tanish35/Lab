#include <bits/stdc++.h>
#define ll long long
#define vll vector<long long>
#define db double
#define vi vector<int>
using namespace std;

class Table
{
    vector<vector<int>> v;
    int rows, cols;

public:
    Table(int r, int c) : rows(r), cols(c), v(r, vector<int>(c, 0)) {}
    vector<int> &operator[](int i)
    {
        return v[i];
    }
    friend istream &operator>>(istream &in, Table &t)
    {
        for (int i = 0; i < t.rows; i++)
        {
            for (int j = 0; j < t.cols; j++)
            {
                in >> t.v[i][j];
            }
        }
        return in;
    }
    friend ostream &operator<<(ostream &out, Table &t)
    {
        for (int i = 0; i < t.rows; i++)
        {
            for (int j = 0; j < t.cols; j++)
            {
                out << t.v[i][j] << " ";
            }
            out << "\n";
        }
        return out;
    }
};

int main()
{
    Table t(4, 5), t1(4, 5);
    cin >> t;
    t[0][0] = 5;
    int x = t[2][3];
    t1 = t;
    cout << t << "\n"
         << t1;
    return 0;
}