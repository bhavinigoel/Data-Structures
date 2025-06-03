#include <iostream>
//#include <string>
#include "MyStack.h"
using namespace std;


int op_precedence (char op){
    if(op == '+' || op =='-')
        return 1;
 
    if(op == '*' || op =='/')
        return 2;
 
    if(op == '^')
        return 3;

 
    return 0;
}

string convert(string infix)
{
    int i = 0;
    string postfix = "";

    stack <char>s;

    while(infix[i]!='\0')
    {
     
        if(infix[i]>='a' && infix[i]<='z'|| infix[i]>='A'&& infix[i]<='Z')          
        {
            postfix += infix[i];
            i++;
        }
        
        else if(infix[i]=='(')
        {
            s.push(infix[i]);
            i++;
        }
     
        else if(infix[i]==')')
        {
            while(s.peek()!='('){
                postfix += s.peek();
                s.pop();
            }
            s.pop();
            i++;
        }
        else            
        {
            while (!s.is_empty()==-1 && op_precedence(infix[i]) <= op_precedence(s.peek())){
                postfix += s.peek();
                s.pop();
            }
            s.push(infix[i]);
            i++;
        }
    }
    while(!s.is_empty()==-1){
        postfix += s.peek();
        s.pop();
    }


    cout << "Postfix is : " << postfix;  
    return postfix;
}

int main()
{
    string infix = "((a+b)*(d*e)-f)"; 
    string postfix;
    postfix = convert(infix);
    
    return 0;
}