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
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        int ind = 0;
        vector<int>temp, values;
        while(!q.empty())
        {
            int n = q.size();
            for(int i=0; i<n; i++)
            {
                TreeNode* node = q.front();
                q.pop();
                if(ind % 2 != 0) node->val = temp[n-i-1];
                if(node->left)
                {
                    q.push(node->left);
                    values.push_back(node->left->val);
                }
                if(node->right)
                {
                    q.push(node->right);
                    values.push_back(node->right->val);
                }
            }
            temp = values;
            values.clear();
            ind++;
        }
        return root;
    }
};