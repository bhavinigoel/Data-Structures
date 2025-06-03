#include <iostream>
using namespace std;

struct node {
    int data;
    struct node * next;
};

struct node * front = NULL;
struct node * rear = NULL;


void enqueue(int value) {
    struct node * ptr;
    ptr = new node();
    ptr -> data = value;
    ptr -> next = NULL;
    if ((front == NULL) && (rear == NULL)) {
        front = rear = ptr;
    } else {
        rear -> next = ptr;
        rear = ptr;
    }
    cout<<"Node is Inserted\n";
}


int dequeue() {
    if (front == NULL) {
        cout<<"\nUnderflow\n";
        return -1;
    } else {
        struct node * temp = front;
        int temp_data = front -> data;
        front = front -> next;
        free(temp);
        return temp_data;
    }
}


void display() {
    struct node * temp;
    if ((front == NULL) && (rear == NULL)) {
        cout<<"\nQueue is Empty\n";
    } else {
        cout<<"The queue is \n";
        temp = front;
        while (temp) {
            cout<< temp -> data;
            temp = temp -> next;
        }
       
    }
}

int main() {
    int choice, value;
    cout<<"\nImplementation of Queue using Linked List";
    while (choice != 4) {
        cout<<"\n1.Enqueue\n2.Dequeue\n 3.Display\n 4.Exit\n";
        cout<<"\nEnter your choice : ";
        cin>>choice;
        switch (choice) {
            case 1:
                cout<<"\nEnter the value to insert: ";
                cin>>value;
                enqueue(value);
                break;
            case 2:
                cout<<"Popped element is"<< dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
                break;
            default:
                cout<<"\nWrong Choice\n";
        }
    }
    return 0;
}