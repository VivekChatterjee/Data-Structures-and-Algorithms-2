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
    TreeNode* delNode(TreeNode* root, int key)
    {
        if(!root) return NULL;
        else if(root->val == key)
        {
            TreeNode* left=root->left;
            TreeNode* right=root->right;
            TreeNode* head=right;
            while(right && right->left)
            {
                right=right->left;
            }
            if(right)
            {
                right->left=left;
            }
            else
            {
                head=left;
            }
            return head;
        }
        else if(root->val > key)
        {
            root->left = delNode(root->left, key);
        }
        else
        {
            root->right = delNode(root->right, key);
        }
        return root;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        // if(!root) return NULL;
        // else if(root->val == key)
        // {
        //     TreeNode* left=root->left;
        //     TreeNode* right=root->right;
        //     TreeNode* head=right;
        //     while(right && right->left)
        //     {
        //         right=right->left;
        //     }
        //     if(right)
        //     {
        //         right->left=left;
        //         return head;
        //     }
        //     else
        //     {
        //         return left;
        //     }
        // }
        
        return delNode(root, key);
    }
};