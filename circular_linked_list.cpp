#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
};

void display(struct node **p)
{
    node *t;
    t = *p;
    if (t == NULL)
    {
        cout << " List is Empty" << endl;
    }
    if (*p != NULL)
    {
        do
        {
            cout << t->data << endl;
            t = t->next;
        } while (t != *p);
    }
}

struct node *insert_at_front(node **start)
{
    struct node *t;
    t = *start;
    int info;
    node *n = new node();
    cout << " Enter the info" << endl;
    cin >> info;
    n->data = info;
    if (*start == NULL)
    {
        *start = n;

        (*start)->next = *start;
    }
    else
    {
        while (t->next != *start)
        {
            t = t->next;
        }

        t->next = n;
        n->next = *start;
        *start = n;
    }
}

struct node *insert_at_end(node *start)
{
    struct node *t;
    t = start;
    int info;
    node *n = new node();
    cout << " Enter the info" << endl;
    cin >> info;
    n->data = info;
    if (start == NULL)
    {
        start = n;

        (start)->next = start;
    }
    else
    {
        while (t->next != start)
        {
            t = t->next;
        }

        t->next = n;
        n->next = start;
    }
    return start;
}

void insert_middle(node *start, int Data, int target)
{
    node *ptr = start;
    node *p = new node();
    do
    {
        if (ptr->data == target)
        {
            p->data = Data;
            p->next = ptr->next;
            ptr->next = p;
            return ;
        }
       
        ptr = ptr->next;
    } while (ptr != NULL);
    
    free(p);
        cout << " value not found" << endl;
      
}

node *delete_front(node *start)
{
    struct node *t = start;
    if (start == NULL)
        cout << "empty list" << endl;
    else if (start->next == start)
    {
        free(start); 
        start = NULL; 
    }
    else
    {
        while (t->next->next != start)
        {
            t = t->next;
        }
        start = start->next; 
        free(t->next); 
        t->next = start; 
    }
    return (start);
}


node *del_last(node *start)
{
    struct node *t = start;
    if (start == NULL)
        printf("\nempty list");
    else if (start->next == start)
    {
        free(start);
        start = NULL;
    }
    else
    {
        while (t->next->next != start)
            t = t->next;
        free(t->next);
        t->next = start;
    }
    return start;
}


int main()
{
    node *n1;
    node *n2;
    node *n3;
    n1 = new node();
    n2 = new node();
    n3 = new node();

    n1->data = 1;
    n2->data = 2;
    n3->data = 3;
    n1->next = n2;
    n2->next = n3;
    n3->next = n1;
    while (true)
    {
        cout << "Enter 1 to display Linked list" << endl;
        cout << "Enter 2 to insert at the beginning of Linked list" << endl;
        cout << "Enter 3 to insert at the end of Linked list" << endl;
        cout << "Enter 4 to insert in the middle" << endl;
        cout << "Enter 5 to delete a node at front" << endl;
        cout << "Enter 6 to delete a node at end" << endl;

        int choice;
        cin >> choice;

        switch (choice)
        {

        case 1:
        {
            cout << " Your Linked List is:" << endl;
            display(&n1);
            break;
        }

        case 2:
        {
            insert_at_front(&n1);
            break;
        }
        case 3:
        {
            insert_at_end(n1);
            break;
        }
        case 4:
        {
            int value;
            int data_inset;
            cout << " Enter the value after which you want to insert a new node" << endl;
            cin >> value;
            cout << " Enter the data of the node " << endl;
            cin >> data_inset;
            insert_middle(n1, data_inset, value);
            cout << "Element Inserted!" << endl;
            break;
        }
        case 5:
        {
            delete_front(n1);
            break;

        }
        case 6:{

            del_last(n1);
            break;

        }
        default:{
        cout<<"Enter valid number"<<endl;
        }

        }
    }
}