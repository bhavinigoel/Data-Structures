#include <iostream>
using namespace std;
const int MAX_SIZE = 50;

class Queue {
private:
    int data[MAX_SIZE];
    int front, rear, size;

public:
    Queue() {
        front = rear = -1;
        size = 0;
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == MAX_SIZE;
    }

    void insert_rear(int item) {
        if (isFull()) {
            cout << "Queue is full" << endl;
            return;
        }

        if (front == -1) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % MAX_SIZE;
        }

        data[rear] = item;
        size++;
    }

    int remove_front() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return -1;
        }

        int item = data[front];
        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % MAX_SIZE;
        }

        size--;
        return item;
    }

    void reverseFirstKElements(int k) {
        if (isEmpty() || k <= 0 || k > size) {
            cout << "Invalid value of k or empty queue." << endl;
            return;
        }

        int stack[MAX_SIZE];
        int top = -1;

        
        for (int i = 0; i < k; i++) {
            stack[++top] = remove_front();
        }


        for (int i = 0; i < k; i++) {
            insert_rear(stack[top--]);
        }

        for (int i = 0; i < size - k; i++) {
            insert_rear(remove_front());
        }
    }
};

int main() {
    Queue q;

    for (int i = 1; i <= 5; i++) {
        q.insert_rear(i);
    }

    int k;
    cout << "Enter the value of k: ";
    cin >> k;

    q.reverseFirstKElements(k);

  
    while (!q.isEmpty()) {
        cout << q.remove_front() << " ";
    }

    return 0;
}