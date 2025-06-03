#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
} *top =NULL;
void push()
{
    int val;
    cout<<" Enter the value of the data"<<endl;
    cin >> val;

    node *p = new node();
    p->data = val;
    p->next = top;
    top = p;
}

void pop(){

    if( top==NULL){
    cout<<" Stack underflow"<<endl;
    return;}

    node *p =top;
    top=top->next;
    free(p);
    cout<<" Element deleted"<<endl;

}
 void display()
{  node *p=top;
if( top==NULL)
cout<<" stack is empty"<<endl;
else{
    cout<<" Stack as follows:"<<endl;
while(p!=NULL){
    cout<<p->data<<endl;
    p=p->next;
}
}

}

void peek(){
    node *p=top;
     int count=0;
    while(p->next!= NULL){
        p=p->next;
        count++;
    }
    cout<<" The Last element is: "<<p->data<<endl;
    cout<<" No of elements in the Stack are :"<< (count+1)<<endl;
}
 int main(){
     while (true)
    {
        int choice;
        cout << " Enter your choice?" << endl;
        cout << "1 To Enter an element in stack" << endl;
        cout << "2 To pop an element from stack" << endl;
        cout << "3 To know the last elemnt" << endl;
        cout << "4 to display the stack" << endl;
        cout << "5 to Exit" << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            push();
            break;
        }
        case 2:
        {
            pop();
            break;
        }
        case 3:
        {
            peek();
            break;
        }
        case 4:
        {
            display();
            break;
        }
        case 5:
            return false;
        }
    }
}


 