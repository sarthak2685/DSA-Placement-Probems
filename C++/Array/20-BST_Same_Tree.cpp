// CPP Program to check whether the given trees are the same or not.

#include <iostream>
#include <queue>
using namespace std;



// TreeNode structure:
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    // Constructor for TreeNode:
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};




// class Tree containing the isSameTree function:
class Tree
{
public:
    // check if two trees are the same:
    bool isSameTree(TreeNode *tree_A, TreeNode *tree_B)
    {
        // If both trees are empty (base case),
        // they are the same:
        if (tree_A == NULL && tree_B == NULL)
        {
            return true;
        }

        // If one of the trees is empty while the other is not,
        // they are not the same:
        if (tree_A == NULL || tree_B == NULL)
        {
            return false;
        }

        // If values of the current nodes are different,
        // the trees are not the same:
        if (tree_A->val != tree_B->val)
        {
            return false;
        }

        // Recursively check the left and right subtrees:
        return isSameTree(tree_A->left, tree_B->left) && isSameTree(tree_A->right, tree_B->right);
    }
};




// Function to create a binary tree from a level-order traversal representation:
TreeNode *createTree(vector<int> &tree_value)
{
    if (tree_value.empty())
        return NULL;

    int index = 0;
    int n = tree_value.size();

    TreeNode *root = new TreeNode(tree_value[index++]);
    queue<TreeNode *> nodes;
    nodes.push(root);

    while (index < n)
    {
        TreeNode *current = nodes.front();
        nodes.pop();

        int leftValue = tree_value[index++];
        if (leftValue != -1)
        {
            current->left = new TreeNode(leftValue);
            nodes.push(current->left);
        }

        if (index < n)
        {
            int rightValue = tree_value[index++];
            if (rightValue != -1)
            {
                current->right = new TreeNode(rightValue);
                nodes.push(current->right);
            }
        }
    }

    return root;
}




int main()
{
    Tree same_tree_obj;

    // Entering the values for two trees:
    vector<int> tree1_val = {100, 200, NULL};
    vector<int> tree2_val = {100, 200, 300};

    // Creating tree objects using the createTree function
    TreeNode *tree1 = createTree(tree1_val);
    TreeNode *tree2 = createTree(tree2_val);

    // Check if the two trees are the same and print the result
    if (same_tree_obj.isSameTree(tree1, tree2))
    {
        cout << "The given trees are the same." << endl;
    }
    else
    {
        cout << "The given trees are not the same." << endl;
    }

    return 0;
}