#include <bits/stdc++.h>

using namespace std;


struct node
{
    int data;
    struct node *left, *right;
};


struct node *newNode(int data)
{
    struct node *node = (struct node *)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return (node);
}

int findCeil(node *root, int input)
{

    int ceil = -1;
    
    while (root)
    {
        
        if (root->data == input)
            return input;

        else if (root->data < input)
        {
            root = root->right;
        }

       
        else
        {
            ceil = root->data;
            root = root->left;
        }
    }

    
    return ceil;
}

int main()
{
    
    struct node *root = newNode(10);
    root->left = newNode(5);
    root->left->left = newNode(4);
    root->left->right = newNode(7);
    root->left->right->right = newNode(8);
    root->right = newNode(11);

    cout << findCeil(root, 6);
    cout << endl;

    return 0;
}