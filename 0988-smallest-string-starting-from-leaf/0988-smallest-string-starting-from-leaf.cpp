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
    set<string>s;
    void dfs(TreeNode* root, string st)
    {
        if(!root) return;
        if(!root->left && !root->right)
        {
            string ss = st;
            reverse(ss.begin(), ss.end());
            s.insert(ss);
            return;
        }
        if(root->left)
        {
            char c = root->left->val + 'a';
            dfs(root->left, st+c);
        }
        if(root->right)
        {
            char c = root->right->val + 'a';
            dfs(root->right, st+c);
        }        
    }
    string smallestFromLeaf(TreeNode* root) {
        char c = root->val + 'a';
        string st="";
        st+=c;
        dfs(root, st);
        return *s.begin();
    }
};