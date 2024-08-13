#include <iostream>
using namespace std;

class Queue
{
    int *data;
    int front, rear, size;

public:
    Queue(int size)
    {
        data = new int[size];
        front = rear = -1;
        this->size = size;
    }
    void add(int element)
    {
        if (rear == size - 1)
        {
            cout << "Queue is full" << endl;
            return;
        }
        rear++;
        data[rear] = element;
    }
    int remove()
    {
        if (front == rear)
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
        front++;
        return data[front];
    }
    void display()
    {
        for (int i = front + 1; i <= rear; i++)
        {
            cout << data[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    Queue q(5);
    q.add(1);
    q.add(2);
    q.add(3);
    q.add(4);
    q.add(5);
    q.display();
    q.remove();
    q.display();
    return 0;
}
