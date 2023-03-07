class Solution {
public:
    int K=1e9+7;
    int ways(int i, vector<vector<int>> &types, int target, vector<vector<int>> &dp)
    {
        int n=types.size();
        if(i==n || target<=0)
        {
            return target==0;
        }
        if(dp[i][target]!=-1) return dp[i][target];
        int dontPickAndMove=0, pickAndMove=0;
        for(int k=1; k<=types[i][0]; k++)
        {
            pickAndMove=(pickAndMove+ways(i+1, types, target-(k*types[i][1]), dp))%K;
        }
        dontPickAndMove=(dontPickAndMove+ways(i+1, types, target, dp))%K;
        return dp[i][target]=(dontPickAndMove+pickAndMove)%K;
    }
    int waysToReachTarget(int target, vector<vector<int>>& types) {
        int n=types.size();
        vector<vector<int>> dp(n+1, vector<int>(target+1, -1));
        return ways(0, types, target, dp);
    }
};