class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        TreeNode* ans;
        while(root!=NULL)
        {
            int curr=root->val;
            if((curr> p->val) && (curr >q->val))
            {
                root=root->left;
            }
            else if((curr< p->val) && (curr <q->val))
            {
                root=root->right;
            }
            else{
                ans=root;
                break;
            }
        }

        return ans;
    }
};