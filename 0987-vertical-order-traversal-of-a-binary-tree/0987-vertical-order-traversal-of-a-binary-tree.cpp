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
    vector<vector<int>> verticalTraversal(TreeNode* root) 
    {
        map<int, map<int, multiset<int>>>m;
        // vertical order, Level, Elements
        queue<pair<TreeNode*, pair<int, int>>>q;
        // node, level, order
        q.push({root, {0, 0}});
        while(!q.empty())
        {
            int n=q.size();
            for(int i=0; i<n; i++)
            {
                TreeNode* node=q.front().first;
                int level=q.front().second.first;
                int order=q.front().second.second;
                q.pop();
                m[order][level].insert(node->val);
                if(node->left) q.push({node->left, {level+1, order-1}});
                if(node->right) q.push({node->right, {level+1, order+1}});
            }
        }
        vector<vector<int>>ans;
        for(auto i: m)
        {
            vector<int>cur;            
            for(auto j: i.second)
            {
                for(auto k: j.second)
                {
                    cur.push_back(k);
                }
            }
            ans.push_back(cur);
        }
        return ans;
    }
};