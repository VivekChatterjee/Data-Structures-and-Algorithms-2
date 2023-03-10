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
#define ll long long
class Solution {
public:
    long long kthLargestLevelSum(TreeNode *root, int k)
    {
        priority_queue<ll, vector<ll>, greater<ll>> p;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            int n = q.size();
            ll sum = 0;
            for (int i = 0; i < n; i++)
            {
                TreeNode *node = q.front();
                q.pop();
                sum += (ll)node->val;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
                // cout<<sum<<endl;
            }
            p.push(sum);
            if (p.size() > k)
                p.pop();
        }
        if (p.size() < k)
            return -1;
        return p.top();
    }
};