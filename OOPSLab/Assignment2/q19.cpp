#include <iostream>

using namespace std;

class Vector
{
public:
    int *arr;
    int size;
    Vector(int size)
    {
        this->size = size;
        arr = new int[size];
    }
    Vector equal(Vector &v)
    {
        Vector temp(v.size);
        for (int i = 0; i < v.size; i++)
        {
            temp.arr[i] = v.arr[i];
        }
        return temp;
    }
    void add(Vector &v)
    {
        for (int i = 0; i < v.size; i++)
        {
            arr[i] += v.arr[i];
        }
    }
    void subtract(Vector &v)
    {
        for (int i = 0; i < v.size; i++)
        {
            arr[i] -= v.arr[i];
        }
    }
    bool lessThan(Vector &v)
    {
        for (int i = 0; i < v.size; i++)
        {
            if (arr[i] >= v.arr[i])
            {
                return false;
            }
        }
        return true;
    }
    bool greaterThan(Vector &v)
    {
        for (int i = 0; i < v.size; i++)
        {
            if (arr[i] <= v.arr[i])
            {
                return false;
            }
        }
        return true;
    }
    void display()
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    Vector v1(3);
    Vector v2(3);
    for (int i = 0; i < 3; i++)
    {
        v1.arr[i] = i;
        v2.arr[i] = i + 1;
    }
    v1.add(v2);
    v1.display();
}