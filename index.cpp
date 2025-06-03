#include <iostream>
using namespace std;

struct node
{
   int data;
   struct node *next;
};

void GetNth(node *head, int index) {
    if (index <= 0) {
        cout<<" invalid input"<<endl;
        return  ;
        
    }

    int count = 1;
    node* p = head;

    while (p->next!=NULL) {
        if (count == index) {
           cout<<p->data; 
           return ;
            
        }
        count++;
        p = p->next;
    }
   cout<<" index doesnt exit"<<endl;
}

   

int main()
{

   node *n1;
   node *n2;
   node *n3;
   n1 = new node();
   n2 = new node();
   n3 = new node();

   n1->data = 91;
   n2->data = 62;
   n3->data = 43;
   n1->next = n2;
   n2->next = n3;
   n3->next = NULL;

   cout<<" Enter the index of which you want to find the value"<<endl;
   int index;
   cin>>index;
   GetNth( n1 , index);


}


