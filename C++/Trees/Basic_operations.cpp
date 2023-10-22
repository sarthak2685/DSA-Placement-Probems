
#include <iostream>
#include <queue>
using namespace std;
 
class Node{
    public:
        int data;
        Node* left;
        Node* right;
 
        Node(int d){
            data = d;
            left = NULL;
            right = NULL;
        }
};
 
void insert_node(Node* &root, int d){
    // level order
    if(root == NULL){
        root = new Node(d);
        return;
    }
 
    queue<Node*> q;
    q.push(root);
 
    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
 
        if(temp->left != NULL){
            if(temp->left->data != 0)
                q.push(temp->left);
        }
        else{
            temp->left = new Node(d);
            return;
        }
 
        if(temp->right != NULL){
            if(temp->right->data != 0)
                q.push(temp->right);
        }
        else{
            temp->right = new Node(d);
            return;
        }
    }
}
 
void fixtree(Node* &root){
    queue<Node*> q;
    q.push(root);
 
    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
 
        if(temp->left != NULL){
            if(temp->left->data == 0)
                temp->left = NULL;
            else{
                q.push(temp->left);
            }
        }
 
        if(temp->right != NULL){
            if(temp->right->data == 0)
                temp->right = NULL;
            else{
                q.push(temp->right);
            }
        }
    }
}
 
void insert_array(Node* &root, int arr[], int len){
    for(int i = 0; i<len; i++){
        insert_node(root, arr[i]);
    }
    fixtree(root);
}
 
void preorder(Node* &root){
    if(root==NULL){
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}
 
void inorder(Node* &root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
 
void postorder(Node* &root){
    if(root==NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}
 
void levelorder(Node* &root){
    if(root == NULL){
        return;
    }
 
    queue<Node*> q;
    q.push(root);
 
    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
 
        cout << temp->data << " ";
 
        if(temp->left != NULL){
            q.push(temp->left);
        }
        if(temp->right != NULL){
            q.push(temp->right);
        }
    }
}
 
int main(){
    int numarr[] = {1, 2, 3, 4, 5, 6, 7, 0, 8, 9, 0, 0, 0, 10, 11, 12, 13, 0, 14, 15, 0, 16, 17};
    int len = sizeof(numarr) / sizeof(numarr[0]);
 
    Node* root = NULL;
    insert_array(root, numarr, len);
 
    cout << "Preorder: "; preorder(root);
    cout << "\nInorder: "; inorder(root);
    cout << "\nPostorder: "; postorder(root);
    cout << "\nLevelorder: "; levelorder(root);
 
    return 0;
}
