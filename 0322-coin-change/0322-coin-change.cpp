class Solution {
public:
    int coinChange(vector<int>& arr, int amount) {
        int n=arr.size();
        vector<vector<int>>dp(n, vector<int>(amount+1, 1e8));
        for(int i=0; i<n; i++) dp[i][0]=0;
        for(int j=1; j<=amount; j++)
        {
            if(arr[0]<=j && j%arr[0]==0) dp[0][j]=j/arr[0];
        }
        for(int i=1; i<n; i++)
        {
            for(int j=1; j<=amount; j++)
            {
                if(arr[i]<=j) dp[i][j]=min(dp[i-1][j], 1+dp[i][j-arr[i]]);
                else dp[i][j]=dp[i-1][j];
            }
        }
        return (dp[n-1][amount]==1e8)? -1 : dp[n-1][amount];
    }
};