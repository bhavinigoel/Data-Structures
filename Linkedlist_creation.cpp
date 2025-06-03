#include <iostream>
using namespace std;

struct node
{
   int data;
   struct node *next;
};

struct node *insert_begin(struct node **start)
{
   int value;
   cout << "Enter data to be inserted" << endl;
   cin >> value;

   node *p = new node();
   p->data = value;
   p->next = *start;
   *start = p;
   cout << " Element inserted!" << endl;
}

struct node *insert_end(struct node **r)
{
   struct node *p, *q;
   int value;

   cout << "Enter data to be inserted" << endl;
   cin >> value;

   p = new node();
   p->data = value;
   p->next = NULL;
   if (*r == NULL)
   {
      return p;
   }
   q = *r;
   while (q->next != NULL)
   {
      q = q->next;
   }
   q->next = p;
   cout << "Element inserted !" << endl;
}
void display(node *p)
{
   node *t = p;
   cout << "Linked List is:" << endl;
   while (t != NULL)
   {
      cout << t->data << " ";
      t = t->next;
   }
   cout << endl;
}
  

struct node *delete_node(node *r)
{
   int value;

   cout << "Enter the value you want to delete: ";
   cin >> value;
   node *p, *q;
   p = r;
   q = p; 
   if (r == NULL)
   {
      cout << " Link does not exist" << endl;
      return r; 
   }

   while (p != NULL)
   {
      if (p->data == value)
      {
         if (p == r)
            r = p->next;
         else
            q->next = p->next;
            p->next=NULL;

         free(p);
         return r;
      }
      else
      {
         q = p; 
         p = p->next;
      }
   

   cout << "Value not found in the list" << endl;
   }
   return r; 
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
         ptr->next = p;
         return;
      }
      else
         cout << " value not found" << endl;
      ptr = ptr->next;
   }
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
   while (true)
   {

      int choice;
      cout << " Enter your choice?" << endl;
      cout << "1 to insert at beginning" << endl;
      cout << "2 to insert in middle" << endl;
      cout << "3 to insert at end" << endl;
      cout << "4 to delete a node " << endl;
      cout << "5 to display the linked list" << endl;
      cout << "6 to Exit"<< endl;
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
         insert_end(&n1);
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
