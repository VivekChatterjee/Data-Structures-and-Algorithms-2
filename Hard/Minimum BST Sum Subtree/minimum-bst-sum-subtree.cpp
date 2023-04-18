//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }

    Node *buildTree(string s) {
        if (s.length() == 0 || s[0] == 'N') return NULL;

        // Create the root of the tree
        vector<string> str;
        istringstream iss(s);
        for (string s; iss >> s;) str.push_back(s);
        Node *root = new Node(stoi(str[0]));

        // Push the root to the queue
        queue<Node*> q;
        q.push(root);

        // Starting from the second element
        int i = 1;
        while (q.size() > 0 && i < str.size()) {

            // Get and remove the front of the queue
            Node *currNode = q.front();
            q.pop();

            // Get the current node's value from the string
            string currVal = str[i];

            // If the left child is not null
            if (currVal != "N") {

                // Create the left child for the current node
                currNode->left = new Node(stoi(currVal));
                // Push it to the queue
                q.push(currNode->left);
            }

            // For the right child
            i++;
            if (i >= str.size()) break;

            currVal = str[i];

            // If the right child is not null
            if (currVal != "N") {

                // Create the right child for the current node
                currNode->right = new Node(stoi(currVal));

                // Push it to the queue
                q.push(currNode->right);
            }
            i++;
        }

        return root;
    }

    void inorder(Node *root) {
        if (root == NULL) return;
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
};


// } Driver Code Ends
//User function Template for C++

class Temp{
public:
    int sum;
    bool isBST;
    int count;
    int maxi;
    int mini;
    Temp()
    {
        sum=0;
        isBST=true;
        count=0;
        maxi=INT_MIN;
        mini=INT_MAX;
    }
};

class Solution {
    Temp* solve(int target, Node *root, int &mini)
    {
        if(root==NULL)
        {
            return new Temp();
        }
        Temp* left=solve(target, root->left, mini);
        Temp* right=solve(target, root->right, mini);
        
        Temp* curr=new Temp();
        curr->sum=left->sum+right->sum+root->data;
        curr->isBST=left->isBST && right->isBST && root->data>left->maxi && root->data<right->mini;
        curr->count=left->count+right->count+1;
        curr->maxi=max(root->data, right->maxi);
        curr->mini=min(root->data, left->mini);
        
        if(curr->isBST && curr->sum==target)
        {
            mini=min(mini, curr->count);
        }
        return curr;
    }
public:
    int minSubtreeSumBST(int target, Node *root) {
        // code here
        int mini=INT_MAX;
        solve(target, root, mini);
        if(mini==INT_MAX)
            return -1;
        return mini;
    }
};

//{ Driver Code Starts.


int main(){
    
    int t;
    cin>>t;
    while(t--){
        int target;
        cin>>target;
        string str;
        getline(cin,str);
        getline(cin,str);
        Node node(0);
        Node *root = node.buildTree(str);
        Solution ob;
        int res = ob.minSubtreeSumBST(target, root);
        cout<<res<<endl;
    }
    return 0;
}
// } Driver Code Ends