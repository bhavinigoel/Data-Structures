#include <iostream>
using namespace std;
#include "MyStack.h"
#include "MyQueue.h"

struct tree_node
{
    int info;
    tree_node *left;
    tree_node *right;
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
    }
    else
    {
        if (tree->info >= data)
            tree->left = insert(tree->left, data);
        else
            tree->right = insert(tree->right, data);
    }
    return (tree);
}

void Traversal_pre_order(tree_node *root)
{
    stack<tree_node *> s;
    tree_node *temp = root;
    s.push(0);

    cout << temp->info << endl;

    while (s.is_empty() != -1)
    {

        if (temp->right != NULL)
        {

            s.push(temp->right);
        }
        if (temp->left != NULL)
        {
            cout << (temp->left)->info << endl;
            temp = temp->left;
        }
        else
        {
            cout << (s.peek())->info << endl;
            temp = s.peek();
            s.pop();
        }
    }
}

void InOrder(tree_node *root)
{
    tree_node *temp = root;
    stack<tree_node *> s1;

    s1.push(0);
    while (s1.is_empty() != -1)
    {
        while (temp != NULL)
        {
            s1.push(temp);
            temp = temp->left;
        }
        temp = s1.peek();

        cout << temp->info << endl;
        s1.pop();
        temp = temp->right;
    }
}
void postOrderIterative(tree_node *root)
{
    if (root == NULL)
        return;

    stack<tree_node *> s1, s2;

    s1.push(root);
    tree_node *node;

    while (s1.is_empty() != -1)
    {

        node = s1.peek();
        s1.pop();
        s2.push(node);

        if (node->left)
            s1.push(node->left);
            
        if (node->right)
            s1.push(node->right);
    }

    while (s2.is_empty() != -1)
    {
        node = s2.peek();
        s2.pop();
        cout << node->info << endl;
    }
}
int main()
{

    root = insert(root, 11);
    root = insert(root, 12);
    root = insert(root, 9);
    root = insert(root, 5);
     //Traversal_pre_order(root);
     InOrder(root);
    cout<<"--------****---------"<<endl;
    //postOrderIterative(root);
}