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
    pair<int, int> findCount(TreeNode* root, int &ans)
    {
        if(!root) return {0, 0};
        auto left = findCount(root->left, ans);
        auto right = findCount(root->right, ans);
        int sum = left.first + right.first + root->val;
        int count = left.second + right.second + 1;
        ans += ((sum / count) == root->val);
        return {sum, count};
    }
    int averageOfSubtree(TreeNode* root) {
        int ans = 0;
        findCount(root, ans);
        return ans;
    }
};