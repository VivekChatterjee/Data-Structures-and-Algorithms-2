class Solution {
public:
    void dfs(int i, int j, int &original, int &color, vector<vector<int>>& grid, vector<vector<int>>& vis, vector<vector<int>>& ans)
    {
        int m = grid.size(), n = grid[0].size();
        vis[i][j] = 1;
        vector<int> row = {0, -1, 0, 1}, col = {-1, 0, 1, 0};
        for(int ii=0; ii<4; ii++)
        {
            int r = row[ii] + i;
            int c = col[ii] + j;
            if(r>=0 && r<m && c>=0 && c<n)
            {
                if(grid[r][c] == original && !vis[r][c])
                    dfs(r, c, original, color, grid, vis, ans);
            }
        }
        if(i == 0 || i == m-1 || j == 0 || j == n-1) ans[i][j] = color;
        else
        {
            for(int ii=0; ii<4; ii++)
            {
                int r = row[ii] + i;
                int c = col[ii] + j;
                if(r>=0 && r<m && c>=0 && c<n)
                {
                    if(grid[r][c] != original) ans[i][j] = color;
                }
            }            
        }
    }
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col,
    int color) 
    {
        int m = grid.size(), n = grid[0].size();
        int original = grid[row][col];
        vector<vector<int>>vis(m, vector<int>(n)), ans = grid;
        dfs(row, col, original, color, grid, vis, ans);
        return ans;
    }
};