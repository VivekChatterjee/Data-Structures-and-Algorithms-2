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
    bool symmetric(TreeNode* left, TreeNode* right)
    {
        if(!left && !right) return 1;
        else if(!left || !right) return 0;
        return left->val == right->val && symmetric(left->right, right->left) && symmetric(left->left, right->right);
    }
    bool isSymmetric(TreeNode* root) {
        return symmetric(root->left, root->right);
    }
};