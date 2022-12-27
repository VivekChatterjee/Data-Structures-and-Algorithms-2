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
    int sumCount(TreeNode* root, unordered_map<TreeNode*, int>&sum)
    {
        if(!root) return 0;
        return sum[root] = root->val + sumCount(root->left, sum) 
        + sumCount(root->right, sum);
    }
    int nodeCount(TreeNode* root, unordered_map<TreeNode*, int>&count)
    {
        if(!root) return 0;
        return count[root] = 1 + nodeCount(root->left, count) 
        + nodeCount(root->right, count);
    }
    void findCount(TreeNode * root, unordered_map<TreeNode*, int>&sum, unordered_map<TreeNode*, int>&count, int &ans)
    {
        if(!root) return;
        if((sum[root] / count[root]) == root->val) ans++;
        findCount(root->left, sum, count, ans);
        findCount(root->right, sum, count, ans);
    }
    int averageOfSubtree(TreeNode* root) {
        unordered_map<TreeNode*, int>sum, count;
        int ans = 0;
        sumCount(root, sum);
        nodeCount(root, count);
        findCount(root, sum, count, ans);
        return ans;
    }
};