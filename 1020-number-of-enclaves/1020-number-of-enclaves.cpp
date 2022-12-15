class Solution {
public:
    void dfs(int i, int j, vector<vector<int>>& grid)
    {
        grid[i][j] = 0;
        int m = grid.size();
        int n = grid[0].size();
        vector<int>row = {-1, 0, +1, 0}, col = {0, -1, 0, +1};
        for(int k=0; k<4; k++)
        {
            int r = i+row[k];
            int c = j+col[k];
            if(r>=0 && r<m && c>=0 && c<n && grid[r][c] == 1)
            {
                dfs(r, c, grid);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if((i == 0 || i == m-1 || j == 0 || j == n-1) && grid[i][j] == 1) 
                    dfs(i, j, grid);
            }
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