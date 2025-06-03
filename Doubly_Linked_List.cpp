#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

void display(struct node *head)
{
    node *t = head;
    if (t == NULL)
    {
        cout << " List is Empty" << endl;
    }
    else
    {
        cout << "Linked List is:" << endl;
        while (t != NULL)
        {
            cout << t->data << endl;
            t = t->next;
        }
    }
}

node *inset_begin(node **head)
{
    int value;
    cout << "Enter data to be inserted" << endl;
    cin >> value;

    node *q = new node();
    q->data = value;
    q->next = NULL;
    q->prev = NULL;
    if (*head == NULL)
    {
        *head = q;
    }
    q->next = *head;
    (*head)->prev = q;
    *head = q;
}
void insert_middle(node *start, int Data, int target)
{
    node *ptr = start;
    node *p = new node();
    while (ptr != NULL)
    {
        if (ptr->data == target)
        {
            p->data = Data;
            p->next = ptr->next;
            p->prev = ptr;
            p->next->prev = p;
            ptr->next = p;

            return;
        }

        ptr = ptr->next;
    }

    free(p);
    cout << " value not found" << endl;
}

node *insert_at_end(node *head)
{
    int value;

    cout << " Enter value to be inserted" << endl;
    cin >>value;

    node *p = new node();
    node *q =head;
    p->data = value;
    p->next = NULL;
    p->prev = NULL;
    if (head == NULL)
    {
       q = p;
        return head;
    }
    else
    {
        while (q->next != NULL)
        {
            q = q->next;
        }
        q->next = p;
        p->prev = q;

        cout << " element inserted" << endl;
        return head;
    }
}

void *delete_node(node *head)
{
    int value;
    node *q;
    q=head;

    cout << "Enter the value you want to delete: ";
    cin >> value;

    while (q != NULL) {
        if (q->data == value) {
            if (q->prev != NULL) {
               q->prev->next =q->next;
            } else {
              
               head =q->next;
            }

            if (q->next != NULL) {
               q->next->prev =q->prev;
            }

            free (q); 
            return head ;
        }
       q =q->next;
    }

    cout << " value not found." << endl;
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
    n3->next = NULL;

    n1->prev = NULL;
    n2->prev = n1;
    n3->prev = n2;

    while (true)
    {

        int choice;
        cout << " Enter your choice?" << endl;
        cout << "1 to insert at beginning" << endl;
        cout << "2 to insert in middle" << endl;
        cout << "3 to insert at end" << endl;
        cout << "4 to delete a node " << endl;
        cout << "5 to display the linked list" << endl;
        cout << "6 to Exit" << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            inset_begin(&n1);
            break;
        }
        case 2:
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

        case 3:
        {
            insert_at_end(n1);
            break;
        }
        case 4:
        {
            delete_node(n1);
            break;
        }
        case 5:
        {
            display(n1);
            break;
        }
        case 6:
            return false;
        }
    }
}
