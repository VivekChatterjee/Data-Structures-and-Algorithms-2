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
    bool sym(TreeNode* left, TreeNode* right)
    {
        if(!left && !right) return 1;
        if(left && !right || (!left && right) || left->val != right->val)
            return 0;
        return sym(left->right, right->left) && sym(left->left, right->right);
    }
    bool isSymmetric(TreeNode* root) {
        if(!root) return 1;
        return sym(root, root);
    }
};