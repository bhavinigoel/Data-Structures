#include <iostream>
using namespace std;
#include <stack>
#include "MyQueue.h"
#include <unordered_map>
stack<int> s;

struct tree_node
{
    int info;
    tree_node *left;
    tree_node *right;
    int freq;
} *root = NULL;

tree_node *getnode()
{
    tree_node *p;
    p = new tree_node();

    return (p);
}

tree_node *freenode(tree_node *p)
{

    free(p);
    return p;
}

tree_node *insert(tree_node *tree, int data)
{    

    if (tree == NULL)
    {
        tree = getnode();
        tree->left = NULL;
        tree->left = NULL;
        tree->info = data;
        tree->freq = 1;
    }
    else
    {
        if (tree->info > data)
            tree->left = insert(tree->left, data);
        else if (tree->info == data)
        {
            tree->freq = tree->freq + 1;
            
        }
        else
            tree->right = insert(tree->right, data);
    }
    return (tree);
}

void postOrderIterative(tree_node *root, unordered_map<int, int> &freq)
{

    if (root == nullptr)
        return;
    postOrderIterative(root->left, freq);
    postOrderIterative(root->right, freq);
    freq[root->info]++;
}
void frequency_check(tree_node *root)
{
    int count = 0;

    if (root == NULL)
        return;

    stack<tree_node *> s1, s2;

    s1.push(root);
    tree_node *node;

    while (!s1.empty())
    {

        node = s1.top();
        s1.pop();
        s2.push(node);

        if (node->left)
            s1.push(node->left);

        if (node->right)
            s1.push(node->right);
    }

    while (!s2.empty())
    {
        node = s2.top();
        s2.pop();
        cout << "frequency of " << node->info<<" is :"<< node->freq << endl;
        if(node->freq > 1){
            s.push(node->info);
        }
       
    }
   
}



int main()
{

    tree_node *loc = nullptr;
    tree_node *parent = nullptr;
    int n;
    cout << " Enter the no of elements you want " << endl;
    cin >> n;
    int data;
  

    for (int i = 0; i < n; i++)
    {
        cout << " Enter the data" << endl;
        cin >> data;
        
        root = insert(root, data);
    }
    frequency_check( root);
  cout<<" duplicate values are:"<<endl;
  while( !s.empty() ){
    cout<<s.top()<<endl;
    s.pop();
  }

}


   