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
        vector<vector<int>>rev;
        int ind = 0;
        // storing value
        while(!q.empty())
        {
            vector<int>level;
            int n = q.size();
            for(int i=0; i<n ;i++)
            {
                TreeNode* node = q.front();
                q.pop();
                if(ind % 2 != 0) level.push_back(node->val);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            ind++;
            if(!level.empty())
            {
                reverse(level.begin(), level.end());
                rev.push_back(level);
            }
        }
    
        // reversing value
        int vecInd = -1;
        ind = 0;
        queue<TreeNode*>q2;
        q2.push(root);
        while(!q2.empty())
        {
            vector<int>level;
            int n = q2.size();
            int elementInd = 0;
            if(ind % 2 != 0) vecInd++;
            for(int i=0; i<n ;i++)
            {
                TreeNode* node = q2.front();
                q2.pop();
                if(ind % 2 != 0)
                {
                    node->val = rev[vecInd][elementInd];
                    elementInd++;
                }
                if(node->left) q2.push(node->left);
                if(node->right) q2.push(node->right);
            }
            ind++;
        }
        return root;
    }
};