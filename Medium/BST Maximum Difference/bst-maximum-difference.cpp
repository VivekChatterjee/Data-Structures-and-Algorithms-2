//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node *right;
    Node *left;

    Node(int x) {
        data = x;
        right = NULL;
        left = NULL;
    }
};

Node *insert(Node *tree, int val) {
    Node *temp = NULL;
    if (tree == NULL) return new Node(val);

    if (val < tree->data) {
        tree->left = insert(tree->left, val);
    } else if (val > tree->data) {
        tree->right = insert(tree->right, val);
    }

    return tree;
}


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    // int sumTillTarget=0, ans=0; bool dec=0;
    // Node*tar=NULL;
    // void findSumTillTarget(Node* root, int target)
    // {
    //     if(!root) return;
    //     if(root->data==target) 
    //     {
    //         tar=root;
    //         return;
    //     }
    //     sumTillTarget+=root->data;
    //     if(target>root->data)
    //     findSumTillTarget(root->right, target);
    //     else
    //     findSumTillTarget(root->left, target);
    // }
    // void findSumTillLeaf(Node* root, int sum)
    // {
    //     if(!root)
    //     {
    //         if(!dec)
    //         {
    //             ans=sumTillTarget-sum;
    //             dec=1;
    //         }
    //         else
    //         {
    //             ans=max(ans, sumTillTarget-sum);
    //         }
    //         return;
    //     }
    //     if(!root->left && !root->right)
    //     {
    //         sum+=root->data;
    //         if(!dec)
    //         {
    //             ans=sumTillTarget-sum;
    //             dec=1;
    //         }
    //         else
    //         ans=max(ans, sumTillTarget-sum);
    //     }
    //     if(root->left)
    //     {
    //         findSumTillLeaf(root->left, sum+root->data);
    //     }
    //     else
    //     {
    //         findSumTillLeaf(root->right, sum+root->data);
    //     }
    //     if(root->right)
    //     {
    //         findSumTillLeaf(root->right, sum+root->data);
    //     }
    //     else
    //     {
    //         findSumTillLeaf(root->left, sum+root->data);
    //     }
    // }
    // int maxDifferenceBST(Node *root, int target){
    //     if(!root || root->data == target) return -1;
    //     findSumTillTarget(root, target);
    //     if(!tar) return -1;
    //     findSumTillLeaf(tar->left, 0);
    //     findSumTillLeaf(tar->right, 0);
    //     return ans;
    // }
    int dfs(Node *root, int up_sum)
{
    // if it's null then return 1e8 as a max value
    if (root == nullptr)
        return 1e8;

    // if it's leaf node then return root->data
    if (root->left == nullptr and root->right == nullptr)
        return root->data;

    // find left sum
    int left = dfs(root->left, up_sum);
    // find right sum
    int right = dfs(root->right, up_sum);

    // who is maximum
    if (up_sum - left >= up_sum - right)
        return root->data + left;
    else
        return root->data + right;
}
int maxDifferenceBST(Node *root, int target)
{
    int upSum = 0;
    while (root != nullptr)
    {
        // if target found
        if (root->data == target)
        {
            // find left leaf node sum
            int left = dfs(root->left, upSum);

            // find right leaf node sum
            int right = dfs(root->right, upSum);

            // if left and right contain 1e8 means it's leaf node, so return upper sum
            if (left == 1e8 and right == 1e8)
                return upSum;

            // otherwise return max diff
            return max(upSum - left, upSum - right);
        }

        // add up upper sum root->data
        upSum += root->data;

        // target lesser than root->data, we go left side
        if (root->data > target)
            root = root->left;
        // otherwise right side
        else
            root = root->right;
    }

    // target not found
    return -1;
}
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        Node *root = NULL;

        int N;
        cin >> N;
        for (int i = 0; i < N; i++) {
            int k;
            cin >> k;
            root = insert(root, k);
        }

        int target;
        cin >> target;
        Solution ob;
        cout << ob.maxDifferenceBST(root, target);
        cout << endl;
    }
}
// } Driver Code Ends