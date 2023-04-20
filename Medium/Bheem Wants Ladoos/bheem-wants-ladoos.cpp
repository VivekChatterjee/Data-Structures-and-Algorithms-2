//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}

Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}


// } Driver Code Ends
/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/
class Solution
{
    public:
    Node* h=NULL;
    void dfs(Node* root, int home, unordered_map<Node*, Node*>&par, Node* parent)
    {
        if(!root) return;
        par[root]=parent;
        if(root->data==home) h=root;
        dfs(root->left, home, par, root);
        dfs(root->right, home, par, root);
    }
    int ladoos(Node* root, int home, int k)
    {
        unordered_map<Node*, Node*>par;
        dfs(root, home, par, NULL);
        int sum=0;
        unordered_map<Node*, int>m;
        queue<Node*>q;
        q.push(h);
        m[h]++;
        while(!q.empty())
        {
            int n=q.size();
            while(n--)
            {
                Node* node=q.front();
                q.pop();
                sum+=node->data;
                if(k>0)
                {
                    if(node->left && !m.count(node->left))
                    {
                        q.push(node->left);
                        m[node->left]++;
                    }
                    if(node->right && !m.count(node->right))
                    {
                        q.push(node->right);
                        m[node->right]++;
                    }
                    if(par[node] && !m.count(par[node]))
                    {
                        q.push(par[node]);
                        m[par[node]]++;
                    }
                }
            }
            k--;
        }
        return sum;
    }
};


//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    getchar();
    
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* root = buildTree(s);
        
        int home,k;
        cin>> home >> k;
        getchar();
        Solution obj;
        cout<< obj.ladoos(root,home,k) << endl;
    }
	return 0;
}


// } Driver Code Ends