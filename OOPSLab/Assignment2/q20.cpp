#include <iostream>
using namespace std;

class IntArray
{
public:
    int *arr;
    int size;
    IntArray(int size)
    {
        this->size = size;
        arr = new int[size];
    }
    void display()
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    void add(IntArray &v)
    {
        for (int i = 0; i < v.size; i++)
        {
            arr[i] += v.arr[i];
        }
    }
    void reverse()
    {
        for (int i = 0; i < size / 2; i++)
        {
            int temp = arr[i];
            arr[i] = arr[size - i - 1];
            arr[size - i - 1] = temp;
        }
    }
    void sort()
    {
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size - i - 1; j++)
            {
                if (arr[j] > arr[j + 1])
                {
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    }

    ~IntArray()
    {
        delete[] arr;
    }
};

int main()
{
    IntArray a(5);
    a.arr[0] = 5;
    a.arr[1] = 4;
    a.arr[2] = 3;
    a.arr[3] = 2;
    a.arr[4] = 1;
    a.display();
    a.reverse();
    a.display();
    a.reverse();
    a.display();
    a.sort();
    a.display();
    return 0;
}