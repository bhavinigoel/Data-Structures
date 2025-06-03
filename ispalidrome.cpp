#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

void insert_begin(struct node **start)
{
    int value;
    cout << "Enter data to be inserted" << endl;
    cin >> value;

    node *p = new node();
    p->data = value;
    p->next = *start;
    p->prev = nullptr; // Set prev to nullptr for the first node
    if (*start != nullptr) {
        (*start)->prev = p; // Update the prev pointer of the previous first node
    }
    *start = p;
    cout << "Element inserted!" << endl;
}

void display(node *t)
{  node *p=t;
    cout << "Linked List is:" << endl;
    while (p != nullptr)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

bool isPalindrome(node *start)
{
    if (start == nullptr || start->next == nullptr)
    {
        return true;
    }

    int length = 0;
    node *end = start;

    while (end->next != nullptr)
    {
        end = end->next;
        length++;
    }

    while (start != end)
    {
        if (start->data != end->data)
        {
            return false;
        }
        start = start->next;
        end = end->prev;
    }

    return true;
}

int main()
{
    node *n1 = nullptr; 

    while (true)
    {

        int choice;
        cout << " Enter your choice?" << endl;
        cout << "1 to insert at beginning" << endl;
        cout << "2 to check if list is palindrome" << endl;
        cout << "3 to display the linked list" << endl;
        cout << "4 to Exit" << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            insert_begin(&n1);
            break;
        }
        case 2:
            {
                if (isPalindrome(n1) == true) {
                    cout << "The linked list is a palindrome." << endl;
                } else {
                    cout << "The linked list is not a palindrome." << endl;
                }
                break;
            }

       case 3:
        {
            display(n1);
            break;
        }
        case 4:
            return 0;
        }
    }
}