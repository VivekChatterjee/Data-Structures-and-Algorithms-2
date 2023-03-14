class Solution {
public:
    int ans=0;
    int sumNumbers(TreeNode* root, int cur=0) {
        if(!root) return 0;
        cur=cur*10+root->val;
        if(!root->left && !root->right)
        {
            ans+=cur;
            return ans;
        }
        sumNumbers(root->left, cur);
        sumNumbers(root->right, cur);
        return ans;
    }
};