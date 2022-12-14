class Solution {
public:
    void dfs(int ii, int jj, vector<vector<char>>& grid, vector<vector<int>> &vis)
    {
        int m = grid.size();
        int n = grid[0].size();
        vis[ii][jj] = 1;
        vector<int>row{-1, 0, +1, 0};
        vector<int>col{0,-1,0,+1};
        for(int i=0; i<4; i++)
        {
            int r = ii+row[i];
            int c = jj+col[i];
            if(r>=0 && r<m && c>=0 && c<n && grid[r][c] == '1' && !vis[r][c])
            {
                dfs(r, c, grid, vis);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
         vector<vector<int>> vis(m, vector<int>(n));
        int ans = 0;
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(!vis[i][j] && grid[i][j] == '1')
                {
                    vis[i][j] = 1;
                    ans++;
                    dfs(i, j, grid, vis);
                }
            }
        }
        return ans;
    }
};