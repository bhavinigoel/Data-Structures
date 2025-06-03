#include <iostream>
using namespace std;
const int MAX_SIZE = 50;

class Que
{
private:
    int front = 0;
    int rear = 0;
    int data[MAX_SIZE];

public:
    int enqueue(int d)
    {
        if (front == 1 && rear == MAX_SIZE )
        {
            cout << " Overflow" << endl;
            return 0;
        }

        if (front == 0)
        {
            front = 1;
            rear = 1;
        }
        else if (rear == MAX_SIZE)
            rear = 1;
        else
            rear = rear + 1;

        data[rear]=d;
        return 0;
    }

    bool is_empty()
    {
        return front == 0;
    }

    int deque()
    {
        if (front == 0)
        {
            cout << " Underflow" << endl;
            return 0;
        }

        int item = data[front];
        if (front == rear)
        {
            front = rear = 0;
        }
        else
            front = (front + 1) % MAX_SIZE;
        return 0;
    }

    int getfront()
    {
        if (front == 0)
        {
            cout << " Underflow" << endl;
            return 0;
        }
        else
            return front;

    }
    int get_rear(){
        if( rear==0)
        {
            cout<<" Underflow"<<endl;

        }
        else
        return rear;
    }

    void display()
    {
        int temp = front;
       while (temp != rear)
        {
            cout <<data[temp]<< endl;
            temp = temp + 1;
        } 
        cout<<data[temp]<<endl;
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
        cout << "3 to get the front and Rear" << endl;
        cout << "4 to display" << endl;

        int option;
        cin >> option;

        switch (option)
        {
        case 1:
        {
            cout << " Enter the data" << endl;
            int d;
            cin>>d;
            Q.enqueue(d);

            break;
        }
        case 2:
            Q.deque();
            break;

        case 3:
        {
            int y;
            y= Q.getfront();
            int z;
            z= Q.get_rear();
            cout<<y<<endl;
            cout<<z<<endl;
            break;
        }
        case 4:
            Q.display();
            break;
        }
    }
}
