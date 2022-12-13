class Solution {
public:
    int pathSum(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp)
    {
        int n = grid.size();
        if(i<0 || j<0 || i>=n || j>=n) return 1e7;
        if(i == n-1) return dp[i][j] = grid[i][j];
        if(dp[i][j] != -1) return dp[i][j];
        int cur = grid[i][j], fin = 1e7;
        for(int k=0; k<n; k++)
        {
            if(k != j)
            {
                cur+=pathSum(i+1, k, grid, dp);
                fin = min(fin, cur);
            }
            cur = grid[i][j];
        }
        return dp[i][j] = fin;
    }
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>>dp(n, vector<int>(n, -1));
        int ans = 1e7;
        for(int i = 0; i < n; i++)
            ans = min(ans, pathSum(0, i, grid, dp));
        return ans;
    }
};