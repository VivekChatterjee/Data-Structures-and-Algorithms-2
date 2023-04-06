class Solution {
public:
    void dfs(int i, int j, vector<vector<int>>& grid)
    {
        int m=grid.size(), n=grid[0].size();
        if(i<0 || i>=m || j<0 || j>=n || grid[i][j]==1) return;
        grid[i][j]=1;
        dfs(i+1, j, grid);
        dfs(i-1, j, grid);
        dfs(i, j+1, grid);
        dfs(i, j-1, grid);
    }
    int closedIsland(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size();
        for(int i=0; i<m; i++)
        {
            if(grid[i][0]==0)
            {
                dfs(i, 0, grid);
            }
            if(grid[i][n-1]==0)
            {
                dfs(i, n-1, grid);
            }
        }
        for(int i=0; i<n; i++)
        {
            if(grid[0][i]==0)
            {
                dfs(0, i, grid);
            }
            if(grid[m-1][i]==0)
            {
                dfs(m-1, i, grid);
            }
        }
        int ans=0;
        for(int i=1; i<m-1; i++)
        {
            for(int j=1; j<n-1; j++)
            {
                if(grid[i][j]==0)
                {
                    ans++;
                    dfs(i, j, grid);
                }
            }
        }
        return ans;
    }
};