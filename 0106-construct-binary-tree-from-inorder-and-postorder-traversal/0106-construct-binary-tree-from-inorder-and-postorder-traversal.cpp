class Solution {
public:
    unordered_map<int,int>inMap;
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for(int i=0;i<inorder.size();i++)
            inMap[inorder[i]]=i;
        TreeNode* root = build(inorder,0,inorder.size()-1, postorder,0,postorder.size()-1);
        return root;
    }
    
    TreeNode* build(vector<int>& inorder, int inStart, int inEnd, vector<int>& postorder, int postStart, int postEnd)
    {
        if(inStart > inEnd || postStart > postEnd) return NULL;
        TreeNode* root = new TreeNode(postorder[postEnd]);
        int rootIndex = inMap[root->val];
        int numsInLeft = rootIndex - inStart;
        
        root->left = build(inorder, inStart, rootIndex-1, postorder, postStart, postStart+numsInLeft-1);
        root->right = build(inorder, rootIndex+1, inEnd, postorder, postStart+numsInLeft, postEnd-1);
        return root;
    }
};