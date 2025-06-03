#include <iostream>
using namespace std;
const int MAX_SIZE = 100;


template <typename T>
class stack
{
private:
    T data[MAX_SIZE];
    int top = 0;

public:

    void push(T x)
    {
        if (top == MAX_SIZE)
            cout << "Stack Overflow" << endl;
        top++;
        data[top] = x;
    }

    void pop()
    {
        if (top == 0)
        {
            is_empty();
        }
        top--;
    }

    int is_empty()
    {
        if (top == 0)
        {
            cout << "Stack is empty" << endl;
            return -1;
        }
    }

    T peek()
    {
        if (top == 0)
        {
            is_empty();
        }
        else
        {
            T y;
            y = data[top];
            return y;
        }
    }

    void display()
    {
        if (top == 0)
        {
            is_empty();
        }
        else
        {
            for (int i = 1; i <= top; i++)
            {
                cout << data[i] << endl;
            }
        }
    }
};