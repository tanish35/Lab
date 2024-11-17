#include <bits/stdc++.h>
#define ll long long
#define vll vector<long long>
#define db double
#define vi vector<int>
using namespace std;
using namespace std;

class Stack
{
private:
    int *arr;
    int top;
    int capacity;

public:
    Stack(int size = 10)
    {
        if (size <= 0)
        {
            throw invalid_argument("Stack size must be positive");
        }
        arr = new int[size];
        capacity = size;
        top = -1;
    }

    ~Stack()
    {
        delete[] arr;
    }

    void push(int x)
    {
        if (isFull())
        {
            throw overflow_error("Stack overflow");
        }
        arr[++top] = x;
    }

    int pop()
    {
        if (isEmpty())
        {
            throw underflow_error("Stack underflow");
        }
        return arr[top--];
    }

    int peek() const
    {
        if (isEmpty())
        {
            throw underflow_error("Stack is empty");
        }
        return arr[top];
    }

    bool isEmpty() const
    {
        return top == -1;
    }

    bool isFull() const
    {
        return top == capacity - 1;
    }
};

int main()
{
    try
    {
        Stack stack(5);

        stack.push(1);
        stack.push(2);
        stack.push(3);
        stack.push(4);
        stack.push(5);

        cout << "Top element is: " << stack.peek() << endl;

        stack.pop();
        stack.pop();
        stack.pop();
        stack.pop();
        stack.pop();

        // cout << "Stack is empty: " << stack.isEmpty() << endl;
        stack.pop();
    }
    catch (const exception &e)
    {
        cout << "Exception: " << e.what() << endl;
    }

    return 0;
}