#include <iostream>
using namespace std;

template <typename T, int max_size>
class Que
{
private:
    int front = 0;
    int rear = 0;
    T data[max_size];

public:
    void enqueue(T d)
    {
        if ((front == (rear + 1) % max_size) || (front == 1 && rear == max_size))
        {
            cout << "Overflow" << endl;
            return;
        }

        if (front == 0)
        {
            front = 1;
            rear = 1;
        }
        else if (rear == max_size)
            rear = 1;
        else
            rear = (rear + 1) % max_size;

        data[rear] = d;
    }

    bool is_empty()
    {
        return (rear == 0 && front == 0);
    }

    void deque()
    {
        if (front == 0)
        {
            cout << "Underflow" << endl;
            return;
        }
        T item = data[front];
        if (front == rear)
        {
            front = rear = 0;
        }
        else
            front = (front + 1) % max_size;
    }

    T getfront()
    {
        if (front == 0)
        {
            cout << "Underflow" << endl;
            return 0; 
        }
        else
            return data[front];
    }

    T get_rear()
    {
        if (front == 0)
        {
            cout << "Underflow" << endl;
            return 0; 
        }
        else
            return data[rear];
    }

    void display()
    {
        if (is_empty())
        {
            cout << "Queue is empty." << endl;
            return;
        }

        int temp = front;
        while (temp != rear)
        {
            cout << data[temp] << endl;
            temp = (temp + 1) % max_size;
        }
        cout << data[temp] << endl;
    }
};
