//find if Binary tree has duplicate values

#include <iostream>
#include <queue>
#include <unordered_set>

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

// Function to insert a node into the binary tree non-recursively
void insertNonRecursive(Node*& root, int value) {
    Node* newNode = new Node(value);
    if (root == nullptr) {
        root = newNode;
        return;
    }
    
    std::queue<Node*> q;
    q.push(root);
    
    while (!q.empty()) {
        Node* current = q.front();
        q.pop();
        
        if (current->left == nullptr) {
            current->left = newNode;
            return;
        } else if (current->right == nullptr) {
            current->right = newNode;
            return;
        } else {
            q.push(current->left);
            q.push(current->right);
        }
    }
}

// Function to insert a node into the binary tree recursively
Node* insertRecursive(Node* root, int value) {
    if (root == nullptr) {
        return new Node(value);
    }
    
    if (value <= root->data) {
        root->left = insertRecursive(root->left, value);
    } else {
        root->right = insertRecursive(root->right, value);
    }
    
    return root;
}


bool hasDuplicatesHelper(Node* root, std::unordered_set<int>& uniqueValues) {
    if (root == nullptr) {
        return false;
    }

    if (uniqueValues.count(root->data) > 0) {
        return true;
    }

    uniqueValues.insert(root->data);

    return hasDuplicatesHelper(root->left, uniqueValues) || hasDuplicatesHelper(root->right, uniqueValues);
}

// Function to check whether a binary tree has duplicate values
bool hasDuplicateValues(Node* root) {
    std::unordered_set<int> uniqueValues;
    return hasDuplicatesHelper(root, uniqueValues);
}


int main() {
    Node* root = nullptr;

    // Insert nodes into the binary tree
    insertNonRecursive(root, 5);
    insertNonRecursive(root, 3);
    insertNonRecursive(root, 7);
    insertNonRecursive(root, 2);
    insertNonRecursive(root, 4);
    insertNonRecursive(root, 6);
    insertNonRecursive(root, 8);

    // Alternatively, you can use the recursive insert function:
    // root = insertRecursive(root, 5);
    // root = insertRecursive(root, 3);
    // root = insertRecursive(root, 7);
    // root = insertRecursive(root, 2);
    // root = insertRecursive(root, 4);
    // root = insertRecursive(root, 6);
    // root = insertRecursive(root, 8);


    if (hasDuplicateValues(root)) {
        std::cout << "The binary tree has duplicate values." << std::endl;
    } else {
        std::cout << "The binary tree does not have duplicate values." << std::endl;
    }

   
    return 0;
}


