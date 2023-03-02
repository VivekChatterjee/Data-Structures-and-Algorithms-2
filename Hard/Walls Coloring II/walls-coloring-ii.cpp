//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    // int cost(int i, int prev, vector<vector<int>>&costs, vector<vector<int>> &dp)
    // {
    //     int n=costs.size(), k=costs[0].size();
    //     if(i==n) return 0;
    //     int ans=1e6;
    //     for(int cur=0; cur<k; cur++)
    //     {
    //         if(cur!=prev)
    //         {
    //             if(dp[i][cur]==-1) 
    //             {
    //                 dp[i][cur]=costs[i][cur]+cost(i+1, cur, costs, dp);
    //             }
    //             ans=min(ans, dp[i][cur]);
    //         }
    //     }
    //     return ans;
    // }
    // int minCost(vector<vector<int>> &costs) {
    //     int n=costs.size(), k=costs[0].size();
    //     vector<vector<int>> dp(n, vector<int>(k, -1));
    //     int ans=1e6;
    //     ans=min(ans, cost(0, -1, costs, dp));
    //     if(ans>=1e6) return -1;
    //     return ans;
    // }
    int minCost(vector<vector<int>> &cost) {
        int n = cost.size(), k = cost[0].size();
        if(k == 1){
            if(n == 1)
                return cost[0][0];
            return -1;
        }
        pair<int,int> mini = {INT_MAX,-1}, smini = {INT_MAX,-1};
        for(int i=0; i<k; i++){
            if(cost[0][i] < mini.first){
                smini = mini;
                mini = {cost[0][i], i};
            }
            else if(cost[0][i] < smini.first)
                smini = {cost[0][i], i};
        }
        
        for(int i=1; i<n; i++){
            pair<int,int> curMini = {INT_MAX,-1}, curSmini = {INT_MAX,-1};
            
            for(int j=0; j<k; j++){
                int x = cost[i][j];
                if(j != mini.second)
                    x += mini.first;
                else
                    x += smini.first;
                if(x < curMini.first){
                    curSmini = curMini;
                    curMini = {x, j};
                }
                else if(x < curSmini.first)
                    curSmini = {x, j};
            }
            mini = curMini;
            smini = curSmini;
        }
        return mini.first;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<vector<int>> costs(n, vector<int>(k));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < k; j++) cin >> costs[i][j];
        }
        Solution obj;
        cout << obj.minCost(costs) << endl;
    }
}
// } Driver Code Ends