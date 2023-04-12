class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return root;
        dfs(root->left, root->right);
        return root;
    }
    void dfs(Node* left, Node* right)
    {
        if(!left) return;
        left->next=right;
        dfs(left->left, left->right);
        dfs(left->right, right->left);
        dfs(right->left, right->right);
    }
};