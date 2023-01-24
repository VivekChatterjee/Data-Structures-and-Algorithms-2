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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return {};
        vector<vector<int>>ans;
        queue<TreeNode*>q;
        q.push(root);
        bool lToR=1;
        while(!q.empty())
        {
            int n=q.size();
            vector<int>v(n);
            int st=0, en=n-1;
            for(int i=0; i<n; i++)
            {
                TreeNode* node=q.front();
                if(lToR) v[st++]=(node->val);
                else v[en--]=(node->val);
                q.pop();
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            ans.push_back(v);
            lToR=!lToR;
        }
        return ans;
    }
};