//balancing AVL Tree with rotations.

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    int height;
    Node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
        this->height = 1;
    }
};
int getHeight(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return root->height;
}

Node *createNode(int val)
{
    Node *newNode = new Node(val);
    return newNode;
}


int getBalanceFactor(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return getHeight(root->left) - getHeight(root->right);
}




Node *leftRotate(Node *y)
{

    Node *x = y->right;
    Node *t2 = x->left;

    x->left = y;
    y->right = t2;

    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    return x;
}

Node *rightRotate(Node *x)
{
    Node *y = x->left;
    Node *t2 = y->right;

    y->right = x;
    x->left = t2;

    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    return y;
}

Node *insert(Node *root, int d)
{
    if (root == NULL)
    {
        return createNode(d);
    }
    else
    {
        if (d < root->data)
        {
            root->left = insert(root->left, d);
        }
        else if (d > root->data)
        {
            root->right = insert(root->right, d);
        }
    }
    root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
    int balanceFactor = getBalanceFactor(root);


    if (balanceFactor > 1 && d < root->left->data)
    {
        return rightRotate(root);
    }
    if (balanceFactor < -1 && d > root->right->data)
    {
        return leftRotate(root);
    }
    if (balanceFactor > 1 && d > root->left->data)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    if (balanceFactor < -1 && d < root->right->data)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}

void inorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main()
{
    Node *root = NULL;
    root = insert(root, 4);
    root = insert(root, 7);
    root = insert(root, 6);
    root = insert(root, 0);
    root = insert(root, 2);
    root = insert(root, 1);
    root = insert(root, 8);
    inorder(root);
    return 0;
}

