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
    int ans=INT_MAX, prev=1e5+2;
    void calculate(TreeNode* root)
    {
        if(!root) return;
        calculate(root->left);
        ans=min(ans, abs(root->val-prev));
        prev=root->val;
        calculate(root->right); 
    }
    int minDiffInBST(TreeNode* root) {
        calculate(root);
        return ans;
    }
};