#include <iostream>
using namespace std;

struct Sin_node
{
    int data;
    Sin_node *next;
};

struct doub_node
{
    int data;
    doub_node *next;
    doub_node *prev;
};

void checkSListSize(Sin_node *head, int n)
{
    int count = 0;
    Sin_node *current = head;
    while (current)
    {
        count++;
        current = current->next;
    }

    if (count != n)
    {
        cout << "Error , Size doesnt match" << endl;
    }
    else
        cout<<" Size Matched !"<<endl;

}

void checkDListSize(doub_node *head, int n)
{
    int count = 0;
    doub_node *current = head;
    while (current)
    {
        count++;
        current = current->next;
    }

    if (count != n)
    {
        cout << "Error,Size doesnt match" << endl;
    }
    else
    cout<<" Size Matched!"<<endl;
}

int main()
{

    int single_N = 3;

    Sin_node *n1;
    Sin_node *n2;
    Sin_node *n3;
    n1 = new Sin_node();
    n2 = new Sin_node();
    n3 = new Sin_node();

    n1->data = 1;
    n2->data = 2;
    n3->data = 3;
    n1->next = n2;
    n2->next = n3;
    n3->next = NULL;

    checkSListSize(n1, single_N);

    doub_node *m1;
    doub_node *m2;
    doub_node *m3;
    m1 = new doub_node();
    m2 = new doub_node();
    m3 = new doub_node();

    m1->data = 1;
    m2->data = 2;
    m3->data = 3;

    m1->next = m2;
    m2->next = m3;
    m3->next = NULL;

    m1->prev = NULL;
    m2->prev = m1;
    m3->prev = m2;

    int double_N = 3;

    checkDListSize(m1, double_N);

    return 0;
}