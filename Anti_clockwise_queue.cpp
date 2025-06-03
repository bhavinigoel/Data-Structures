#include <iostream>
using namespace std;
const int MAX_SIZE = 50;

class Que
{
private:
    int front = -1;
    int rear = -1;
    int data[MAX_SIZE];

public:
    int enqueue(int d)
    {
        if ((rear == 0 && front == MAX_SIZE - 1) || rear == front + 1)
        {
            cout << " Overflow" << endl;
            return 0;
        }

        if (front == -1)
        {
            front = MAX_SIZE - 1;
            rear = MAX_SIZE - 1;
        }
        else if (rear == 0)
            rear = MAX_SIZE - 1;
        else
            rear = rear - 1;

        data[rear] = d;
        return 0;
    }
    bool is_full()
    {
        return ((rear == 0 && front == MAX_SIZE - 1) || rear == front + 1);
    }

    bool is_empty()
    {
        return (rear == -1 && front == -1);
    }

    int deque()
    {
        if (front == -1)
        {
            cout << " Underflow" << endl;
            return 0;
        }
        int item = data[front];
        if (front == rear)
        {
            front = rear = -1;
        }
        else if (front == 0)
            front = MAX_SIZE - 1;
        else
            front = front - 1;
        return 0;
    }

    int getfront()
    {
        if (front == -1)
        {
            cout << " Underflow" << endl;
        }
        else
            return data[front];
    }

    int get_rear()
    {
        if (front == -1)
        {
            cout << " Underflow" << endl;
        }
        else
            return data[rear];
    }

    void display()
    {
        int temp = front;
        while (temp != rear)
        {
            cout << data[temp] << endl;
            temp = temp - 1;
        }
        cout << data[temp] << endl;
    }
};

int main()
{
    Que Q;
    while (true)
    {
        cout << "Enter the choice" << endl;
        cout << "1 to insert in queue" << endl;
        cout << "2 to delete in Queue" << endl;
        cout << "3 to get the front and rear" << endl;
        cout << "4 to display" << endl;

        int option;
        cin >> option;

        switch (option)
        {
        case 1:
        {
            cout << " Enter the data" << endl;
            int d;
            cin >> d;
            Q.enqueue(d);
            break;
        }
        case 2:
            Q.deque();
            break;

        case 3:
        {
            int y;
            y = Q.getfront();
            cout << "Front: " << y << endl;
            int z;
            z = Q.get_rear();
            cout << "Rear: " << z << endl;
            break;
        }
        case 4:
            Q.display();
            break;
        }
    }
}
