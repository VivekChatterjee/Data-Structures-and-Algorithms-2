/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int robIt(bool took, TreeNode* root, unordered_map<TreeNode*, map<bool, int>> &dp)
    {
        if(!root) return 0;
        if(!root->left && !root->right)
        {
            if(took) return dp[root][took] = 0;
            else return dp[root][took] = root->val;
        }
        if(dp.count(root) && dp[root].count(took))
            return dp[root][took];
        int take = 0, dont = 0;
        dont += robIt(false, root->left, dp) + robIt(false, root->right, dp);
        if(!took)
            take += root->val + robIt(true, root->left, dp) + robIt(true, root->right, dp);
            
        return dp[root][took] = max(take, dont);
    }
    int rob(TreeNode* root) {
        unordered_map<TreeNode*, map<bool, int>> dp;
        bool took = false;
        return robIt(took, root, dp);
    }
};