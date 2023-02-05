class Solution {
public:
    int path(int i, int j, vector<vector<int>>&dp, vector<vector<int>>&grid)
    {
        if(i<0 || j<0) return 1e8;
        else if(i==0 && j==0) return grid[i][j];
        if(dp[i][j] != -1) return dp[i][j];
        int left=0, up=0;
        left=grid[i][j]+path(i, j-1, dp, grid);
        up=grid[i][j]+path(i-1, j, dp, grid);
        return dp[i][j]=min(left, up);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size();
        vector<vector<int>>dp(m, vector<int>(n, -1));
        return path(m-1, n-1, dp, grid);
    }
};