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
    int ans=0;
    void grand(TreeNode* root, int par, int grandPar)
    {
        if(!root) return;
        if(grandPar % 2 == 0) ans+=root->val;
        grand(root->left, root->val, par);
        grand(root->right, root->val, par);
    } 
    int sumEvenGrandparent(TreeNode* root) {
        grand(root, 1, 1);
        return ans;
    }
};