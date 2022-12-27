/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void dfs(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &m)
    {
        if(!root) return;
        if(root->left)
        {
            m[root->left] = root;
            dfs(root->left, m);
        }
        if(root->right)
        {
            m[root->right] = root;
            dfs(root->right, m);
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*>par, vis;
        dfs(root, par);
        queue<TreeNode*>q;
        q.push(target);
        vector<int>ans;
        int ind = 0;
        while(!q.empty())
        {
            if(ind == k) break;
            int n = q.size();
            for(int i=0; i<n; i++)
            {
                TreeNode* node = q.front();
                q.pop();
                vis[node] = node;
                if(node->left && !vis.count(node->left)) q.push(node->left);
                if(node->right && !vis.count(node->right)) q.push(node->right);
                if(par[node] && !vis.count(par[node])) q.push(par[node]);
            }
            ind++;
        }
        while(!q.empty())
        {
            ans.push_back(q.front()->val);
            q.pop();
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};