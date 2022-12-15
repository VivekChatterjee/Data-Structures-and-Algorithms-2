class Solution {
public:
    void dfs(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& vis)
    {
        vis[i][j] = 1;
        grid[i][j] = 0;
        int m = grid.size();
        int n = grid[0].size();
        vector<int>row = {-1, 0, +1, 0}, col = {0, -1, 0, +1};
        for(int k=0; k<4; k++)
        {
            int r = i+row[k];
            int c = j+col[k];
            if(r>=0 && r<m && c>=0 && c<n && grid[r][c] == 1 && !vis[r][c])
            {
                dfs(r, c, grid, vis);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>vis(m, vector<int>(n));
        // top Boundary row
        for(int i=0; i<n; i++)
        {
            if(!vis[0][i] && grid[0][i] == 1) dfs(0, i, grid, vis);
        }
        // right Boundary row
        for(int i=0; i<m; i++)
        {
            if(!vis[i][n-1] && grid[i][n-1] == 1) dfs(i, n-1, grid, vis);
        }
        // down Boundary row
        for(int i=0; i<n; i++)
        {
            if(!vis[m-1][i] && grid[m-1][i] == 1) dfs(m-1, i, grid, vis);
        }
        // left Boundary row
        for(int i=0; i<m; i++)
        {
            if(!vis[i][0] && grid[i][0] == 1) dfs(i, 0, grid, vis);
        }
        int ans = 0;
        for(int i=1; i<m-1; i++)
        {
            for(int j=1; j<n-1; j++)
            {
                if(grid[i][j] == 1) ans++;
            }
        }
        return ans;
    }
};