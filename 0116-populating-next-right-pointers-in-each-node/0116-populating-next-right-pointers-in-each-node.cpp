class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return root;
        Node * left=root;
        while(left->left)
        {
            Node *cur=left;
            while(cur)
            {
                cur->left->next=cur->right;
                if(cur->next)
                {
                    cur->right->next=cur->next->left;
                }
                cur=cur->next;
            }
            left=left->left;
        }
        return root;
    }
};  