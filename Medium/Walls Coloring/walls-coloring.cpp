//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int cost(int i, int j, vector<vector<int>> &colors, vector<vector<int>> &dp)
    {
        int n=colors.size();
        if(j<0 || j>=3) return 1e8;
        if(i==n-1) return colors[i][j];
        if(dp[i][j] != -1) return dp[i][j];
        int dl=1e8, dr=1e8, dll=1e8, drr=1e8;
        dl=colors[i][j]+cost(i+1, j-1, colors, dp);
        dll=colors[i][j]+cost(i+1, j-2, colors, dp);
        dr=colors[i][j]+cost(i+1, j+1, colors, dp);
        drr=colors[i][j]+cost(i+1, j+2, colors, dp);
        return dp[i][j]=min({dl, dll, dr, drr});
    }
    int minCost(vector<vector<int>> &colors, int n) {
        vector<vector<int>>dp(n, vector<int>(3, -1));
        int ans = min({cost(0, 0, colors, dp), cost(0, 1, colors, dp), cost(0, 2, colors, dp)});
        return ans;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {

        int n;
        cin >> n;
        vector<vector<int>> colors(n, vector<int>(3));
        for (int i = 0; i < n; i++)
            cin >> colors[i][0] >> colors[i][1] >> colors[i][2];
            
        Solution ob;
        cout << ob.minCost(colors, n) << endl;    
    }
}
// } Driver Code Ends