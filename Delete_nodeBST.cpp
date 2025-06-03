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

void Search_Node(tree_node *root, tree_node *&loc, tree_node *&parent, int data)
{
    if (root == NULL)
    {
        loc = NULL;
        parent = NULL;
        cout << "Tree is Empty" << endl;
        return;
    }
    else if (data == root->info)
    {
        loc = root;
        parent = NULL;
        cout << "Node Found!" << endl;
        return;
    }
    else
    {
        tree_node *ptr = root;
        tree_node *save = NULL;

        while (ptr != NULL)
        {
            if (ptr->info == data)
            {
                loc = ptr;
                parent = save;
                cout << "Node Found!" << endl;
                return;
            }
            save = ptr; // Save the parent before moving to the next node

            if (data < ptr->info)
            {
                ptr = ptr->left;
            }
            else
            {
                ptr = ptr->right;
            }
        }

        // Node not found
        loc = NULL;
        parent = save; // Save the last non-null parent
        cout << "Node Not Found!" << endl;
    }
}

void Delete_node(tree_node *root, int d)
{
    tree_node *loc = nullptr;
    tree_node *parent = nullptr;

    Search_Node(root, loc, parent, d);
    if (loc == nullptr)
    {
        cout << "item  not in tree" << endl;
        return;
    }
    if (loc->right != nullptr && loc->left != nullptr)
    {
        tree_node *save;
        tree_node *ptr;
        tree_node *suc;
        tree_node *parsuc;

        // case b
        ptr = loc->right;
        save = loc;
        while (ptr->left != nullptr)
        {
            save = ptr;
            ptr = ptr->left;
        }
        suc = ptr;
        parsuc = save;
        tree_node *chi;
        if (suc->left == nullptr && suc->right == nullptr)
        {
            chi = nullptr;
        }
        else if (suc->left != nullptr)
            chi = suc->left;
        else
            chi = suc->right;

        if (parsuc != nullptr)
        {

            if (suc == parent->left)
                parsuc->left = chi;
            else
                parsuc->right = chi;
        }
        else
            root = chi;
        return;

        if (parent != nullptr)
        {

            if (loc = parent->left)
                parent->left = suc;
            else
                parent->right = suc;
        }
        else
            root = suc;

        suc->left = loc->left;
        suc->right = loc->right;

        return;
    }
    else
    {
        tree_node *child;
        if (loc->left == nullptr && loc->right == nullptr)
        {
            child = nullptr;
        }
        else if (loc->left != nullptr)
            child = loc->left;
        else
            child = loc->right;

        if (parent != nullptr)
        {

            if (loc == parent->left)
                parent->left = child;
            else
                parent->right = child;
        }
        else
            root = child;

        return;
    }
}
void InOrder(tree_node *root )
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
int main()
{

    tree_node *loc = nullptr;
    tree_node *parent = nullptr;
    root = insert(root, 11);
    root = insert(root, 12);
    root = insert(root, 9);
    root = insert(root, 5);

    // Search_Node(root, loc, parent, 5);
    Delete_node(root, 9);
    InOrder(root);
}