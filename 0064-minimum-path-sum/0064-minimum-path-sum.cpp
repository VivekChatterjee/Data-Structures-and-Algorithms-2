class Solution {
public:
    int path(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp)
    {
        if(i<0 || j<0) return 1e7;
        if(i==0 && j==0) return grid[i][j];
        if(dp[i][j] != -1) return dp[i][j];
        int up=1e7, left=1e7;
        up=grid[i][j]+path(i-1, j, grid, dp);
        left=grid[i][j]+path(i, j-1, grid, dp);
        return dp[i][j]=min(up, left);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size();
        vector<vector<int>>dp(m, vector<int>(n, -1));
        return path(m-1, n-1, grid, dp);
    }
};