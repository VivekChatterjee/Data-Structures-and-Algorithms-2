class Solution {
public:
    int distributeCoins(TreeNode* root, int res = 0) {
        traversal(root, res);
        return res;
    }
    int traversal(TreeNode* root, int &res)
    {
        if(!root) return 0;
        int left = traversal(root->left, res);
        int right = traversal(root->right, res);
        res += abs(left) + abs(right);
        return root->val + left + right - 1;
            
    }
};