class Solution {
public:
    void dfs(int row, int col, vector<vector<int>>& grid, int &count)
    {
        grid[row][col] = 0;
        int m = grid.size();
        int n = grid[0].size();
        count++;
        vector<int>r = {0, -1, 0, 1};
        vector<int>c = {-1, 0, 1, 0};
        for(int i=0; i<4; i++)
        {
            int rr = r[i] + row;
            int cc = c[i] + col;
            if(rr >= 0 && rr<m && cc>=0 && cc<n && grid[rr][cc])
            {
                dfs(rr, cc, grid, count);
            }
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(grid[i][j])
                {
                    int count = 0;
                    dfs(i, j, grid, count);
                    ans = max(ans, count);
                }
            }
        }
        return ans;
    }
};