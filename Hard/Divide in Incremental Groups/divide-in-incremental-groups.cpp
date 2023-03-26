//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int ways(int i, int n, int tar, int k, vector<vector<vector<int>>> &dp)
    {
        if(tar<0) return 0;
        if(k==0)
        {
            return tar==0;
        }
        if(dp[i][tar][k] != -1) return dp[i][tar][k];
        int take=0;
        for(int j=i; j<=n; j++)
        {
            take+=ways(j, n, tar-j, k-1, dp);
        }
        return dp[i][tar][k]=take;
    }
    int countWaystoDivide(int n, int k) {
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(n+1, vector<int>(k+1, -1)));
        return ways(1, n, n, k, dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        Solution ob;
        cout << ob.countWaystoDivide(N, K) << endl;
    }
}
// } Driver Code Ends