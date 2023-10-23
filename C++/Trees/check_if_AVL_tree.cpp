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
bool isavl(Node* &root)
{
    if(root==NULL)
    {
        return true;
    }
    int lheight=height(root->left);
    int rheight=height(root->right);
    if(abs(lheight-rheight)>1) return false;
    else return true;
}
int main() {
    Node* root = NULL;
    int n;
    cout << "Enter the values (enter -1 to stop): " << endl;
    while (cin >> n && n != -1) {
        binaryTree(root, n);
    }
    if(isavl(root))
    {
        cout<<"Given tree is an AVL Tree:)"<<endl;
    }
    else{
        cout<<"It is not an AVL Tree:("<<endl;
    }
    return 0;
}