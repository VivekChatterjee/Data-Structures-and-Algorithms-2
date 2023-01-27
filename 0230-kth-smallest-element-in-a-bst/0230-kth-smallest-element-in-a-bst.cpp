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
    int fin, ans=-1;
    void small(TreeNode* root, int &k)
    {
        if(!root) return;
        small(root->left, k);
        k++;
        if(k == fin)
        {
            ans=root->val;
            return;
        }
        small(root->right, k);
    }
    int kthSmallest(TreeNode* root, int k) {
        fin=k;
        int num=0;
        small(root, num);
        return ans;
    }
};