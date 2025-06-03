#include<iostream>
using namespace std;
struct node{
    int data;
    node *next;
    int priority;

};
node* newNode(int d, int p) 
{ 
    node* temp = new node(); 
    temp->data = d; 
    temp->priority = p; 
    temp->next = NULL; 
  
    return temp; 
}

int peek(node** head) 
{ 
    return (*head)->data; 
}
void pop(node** head) 
{ 
    node* temp = *head; 
    (*head) = (*head)->next; 
    free(temp); 
}  
int isEmpty(node** head) 
{ 
    return (*head) == NULL; 
} 

void push(node **head,int data,int p){
           node *temp =*head;
          node *n = newNode(data,p);
    if((*head)->priority > p){
        n->next=*head;
        *head=n;
    }
    else 
    {
        while (temp->next != NULL && 
            temp->next->priority < p) 
        { 
            temp = temp->next; 
        } 
  
        n->next = temp->next; 
        temp->next = n; 
    } 
    }

  int main() 
{ 
      

    node* nw = newNode(4, 1); 
    push(&nw, 5, 2); 
    push(&nw, 6, 3); 
    push(&nw, 7, 0); 
  
    while (!isEmpty(&nw)) 
    { 
        cout << " " << peek(&nw); 
        pop(&nw); 
    } 
    return 0; 
} 