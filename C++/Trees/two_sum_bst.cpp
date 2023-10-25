class Solution {
public:

    void solve(TreeNode* root, vector<int>&v)
    {
        if(root==NULL)
        {
            return ;
        }

        solve(root->left, v);
        v.push_back(root->val);
        solve(root->right, v);
    }
    bool findTarget(TreeNode* root, int k) {

        vector<int>v;

        solve(root, v);

        int l=0, h=v.size()-1;

        if(root->left==NULL && root->right==NULL)return false;

        while(l<h)
        {
            int s=v[l]+v[h];
            if(s>k)
            {
                h--;
            }
            else if( s<k)
            {
                l++;
            }
            else{
                return true;
            }
        }
        return false;
    }
};