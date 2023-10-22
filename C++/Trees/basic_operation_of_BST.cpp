#include <iostream>
#include <queue>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int d) {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

void binaryTree(Node*& root, int d) {
    if (root == NULL) {
        Node* newNode = new Node(d);
        root = newNode;
    }
    else if (d <= root->data) {
        binaryTree(root->left, d);
    }
    else if (d > root->data) {
        binaryTree(root->right, d);
    }
}



void inorder(Node* &root) {
    if (root == NULL) {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
void preorder(Node* &root)
{
    if(root==NULL)
    {
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
void postorder(Node* &root)
{
    if(root==NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}
void level(Node* &root)
{
    queue<Node*> q;
    q.push(root);
    while(!q.empty())
    {
        int nodecount=q.size();
        while(nodecount>0)
        {
            Node* current=q.front();
            q.pop();
            cout<<current->data<<" ";
            if(current->left)
            {
                q.push(current->left);
            }
            if(current->right)
            {
                q.push(current->right);
            }
            nodecount--;
        }
        cout<<endl;
    }
}

int height(Node* &root)
{
    if(root==NULL)
    {
        return 0;
    }
    int left=height(root->left);
    int right=height(root->right);
    int ans=max(left,right)+1;
    return ans;
}

int main() {
    Node* root = NULL;
    int n;
    cout << "Enter the values (enter -1 to stop): " << endl;
    while (cin >> n && n != -1) {
        binaryTree(root, n);
    }
    cout << "Inorder traversal of binary search tree:" << endl;
    inorder(root);
    cout << endl;

    cout << "Preorder traversal of binary search tree:" << endl;
    preorder(root);
    cout << endl;
    
    cout << "Postorder traversal of binary search tree:" << endl;
    postorder(root);
    cout << endl;
    
    cout << "Level traversal of the binary search tree:" << endl;
    level(root);
    cout << endl;
    
    cout<<"Height of tree: "<<endl;
    cout<<height(root);
    return 0;
}
