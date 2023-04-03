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
    int xLevel, yLevel;
    TreeNode *xPar, *yPar;
    void dfs(TreeNode* root, int lvl, TreeNode* parent, int &x, int &y)
    {
        if(!root) return;
        if(root->val==x)
        {
            xPar=parent;
            xLevel=lvl;
        }
        if(root->val==y)
        {
            yPar=parent;
            yLevel=lvl;
        }
        dfs(root->left, lvl+1, root, x, y);
        dfs(root->right, lvl+1, root, x, y);
    }
    bool isCousins(TreeNode* root, int x, int y) {
        if(!root) return 0;
        xLevel=yLevel=0;
        xPar=yPar=NULL;
        dfs(root, 0, NULL, x, y);
        return (xLevel==yLevel && xPar!=yPar);
    }
};