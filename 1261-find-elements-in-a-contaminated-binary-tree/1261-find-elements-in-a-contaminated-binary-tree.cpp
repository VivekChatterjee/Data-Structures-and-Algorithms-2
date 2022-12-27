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
class FindElements {
public:
    TreeNode* r;
    unordered_map<int, bool>isPresent;
    void recover(TreeNode* root, int value)
    {
        if(!root) return;
        root->val = value;
        isPresent[value] = 1;
        if(root->left) recover(root->left, value*2 + 1);
        if(root->right) recover(root->right, value*2 + 2);
    }
    FindElements(TreeNode* root) {
        r = root;
        recover(root, 0);
    }   
    bool find(int target) {
        return isPresent[target];
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */