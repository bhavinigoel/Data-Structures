#include <iostream>
#include "MyStack.h"
#include "MyQueue.h"

Que<int, 20> Q;
stack<int> s;

void recurrsive_reverse(Que<int, 20> &q)
{
    if (q.is_empty())
    {
        return;
    }
    else
    {
        int data = q.getfront();
        q.deque();
        recurrsive_reverse(q);
        q.enqueue(data);
    }
}

void Reverse_Queue(Que<int, 20> &q)
{
    while (!q.is_empty())
    {
        s.push(q.getfront());
        q.deque();
    }
    while (s.is_empty() != -1)
    {
        q.enqueue(s.peek());
        s.pop();
    }
}

int main()
{
    Q.enqueue(20);
    Q.enqueue(10);
    Q.enqueue(30);
    Q.enqueue(40);
    Q.enqueue(50);
    Q.enqueue(60);
    Q.enqueue(70);
    Q.enqueue(80);
    Q.enqueue(90);
    Q.enqueue(100);
    Q.display();
    recurrsive_reverse(Q);
    Reverse_Queue(Q);
    cout << "**********************************" << endl;
    Q.display();

    return 0;
}
