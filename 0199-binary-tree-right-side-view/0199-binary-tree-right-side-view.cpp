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
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return {};
        vector<int>ans;
        queue<TreeNode*>q;
        q.push(root);
        int level=0;
        while(!q.empty())
        {
            int n=q.size();
            for(int i=0; i<n; i++)
            {
                TreeNode* node=q.front();
                q.pop();
                if(level == ans.size())
                {
                    ans.push_back(node->val);
                }
                else if(level<ans.size())
                {
                    ans[level]=node->val;
                }
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            level++;
        }
        return ans;
    }
};