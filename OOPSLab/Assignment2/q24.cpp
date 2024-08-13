#include <iostream>
using namespace std;

class Stack
{
    int *buffer;
    int top;

public:
    Stack(int size)
    {
        buffer = new int[size];
        top = -1;
    }

    void push(int element)
    {
        top++;
        buffer[top] = element;
    }

    int pop()
    {
        int x = buffer[top];
        top--;
        return x;
    }

    void display()
    {
        for (int i = 0; i <= top; i++)
        {
            cout << buffer[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    Stack s(5);
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.display();
    s.pop();
    s.display();
    return 0;
}