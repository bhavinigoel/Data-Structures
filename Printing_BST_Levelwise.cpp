#include <iostream>
using namespace std;
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

tree_node *const delimeter = nullptr;
void printlevelbylevel(tree_node *root)
{
    if (root == delimeter)
        return;

    Que<tree_node *, 100> q;
    q.enqueue(root);
    q.enqueue(delimeter);
    while (true)
    {
        tree_node *curr = q.getfront();
        q.deque();
        if (curr != delimeter)
        {
            cout << curr->info << ' ' << ' ';
            if (curr->left != NULL)
            {
                q.enqueue(curr->left);
            }
            if (curr->right != NULL)
            {
                q.enqueue(curr->right);
            }
        }
        else
        {
            cout << "\n";
            if (q.is_empty())
                break;
            q.enqueue(delimeter);
        }
    }
}
int main()
{
    root = insert(root, 10);
    root = insert(root, 12);
    root = insert(root, 9);
    root = insert(root, 5);
    root = insert(root, 7);
    root = insert(root, 15);
    root = insert(root, 11);
    root = insert(root, 13);

    printlevelbylevel(root);
}
