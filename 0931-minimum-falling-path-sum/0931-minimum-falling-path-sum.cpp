class Solution {
public:
    int pathSum(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>&dp)
    {
        int n = matrix.size();
        if(i<0 || j<0 || i>=n || j>=n) return 1e7;
        if(i == n-1) return matrix[i][j];
        if(dp[i][j] != -1) return dp[i][j];
        int down = 1e7, downL = 1e7, downR = 1e7;
        down = matrix[i][j] + pathSum(i+1, j, matrix, dp);
        downL = matrix[i][j] + pathSum(i+1, j-1, matrix, dp);
        downR = matrix[i][j] + pathSum(i+1, j+1, matrix, dp);
        return dp[i][j] = min(down, min(downL, downR));
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n,-1));
        int ans = INT_MAX;
        for(int i=0; i<n; i++)
            ans = min(ans, pathSum(0, i, matrix, dp));
        return ans;
    }
};