//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {
  public:
    bool pos(int i, int target, int k, vector<int>&coins, vector<vector<vector<int>>> &dp)
    {
        int n=coins.size();
        if(target==0 && k==0) return 1;
        if(i==n || k<0 || target<0) return 0;
        if(dp[i][k][target]!=-1) return dp[i][k][target];
        int dont=0, take=0;
        dont=pos(i+1, target, k, coins, dp);
        if(coins[i]<=target)
        take=pos(i, target-coins[i], k-1, coins, dp);
        return dp[i][k][target]=dont||take;
    }
    bool makeChanges(int n, int k, int target, vector<int> &coins) {
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(k+1, 
        vector<int>(target+1, -1)));
        return pos(0,target, k, coins, dp);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int N;
        scanf("%d", &N);

        int K;
        scanf("%d", &K);

        int target;
        scanf("%d", &target);

        vector<int> coins(N);
        Array::input(coins, N);

        Solution obj;
        bool res = obj.makeChanges(N, K, target, coins);

        cout << res << endl;
    }
}

// } Driver Code Ends