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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        queue<pair<TreeNode*, int>>q; // node, vertical order
        map<int, vector<int>>m; // vertical order, elements
        q.push({root, 0});
        while(!q.empty())
        {
            int n=q.size();
            vector<pair<int, int>>curLevel; // vertical order, elements
            for(int i=0; i<n; i++)
            {
                TreeNode* node=q.front().first;
                int order=q.front().second;
                q.pop();
                curLevel.push_back({order, node->val});
                if(node->left) q.push({node->left, order-1});
                if(node->right) q.push({node->right, order+1});
            }
            sort(curLevel.begin(), curLevel.end());
            for(auto i: curLevel)
            {
                m[i.first].push_back(i.second);
            }
        }
        vector<vector<int>>ans;
        for(auto i: m) ans.push_back(i.second);
        return ans;
    }
};