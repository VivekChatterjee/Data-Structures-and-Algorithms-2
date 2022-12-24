class Solution {
public:
    void removeCorners(int i, int j, vector<vector<int>>& grid)
    {
        grid[i][j] = -1;
        int m = grid.size();
        int n = grid[0].size();
        vector<int>row = {0, -1, 0, +1}, col = {-1, 0, +1, 0};
        for(int num=0; num<4; num++)
        {
            int r = i + row[num];
            int c = j + col[num];
            if(r>=0 && r<m && c>=0 && c<n && grid[r][c] == 0) 
            {
                removeCorners(r, c, grid);
            }
        }
    }
    void closed(int i, int j, vector<vector<int>>& grid)
    {
        grid[i][j] = 1;
        int m = grid.size();
        int n = grid[0].size();
        vector<int>row = {0, -1, 0, +1}, col = {-1, 0, +1, 0};
        for(int num=0; num<4; num++)
        {
            int r = i + row[num];
            int c = j + col[num];
            if(r>=0 && r<m && c>=0 && c<n && grid[r][c] == 0) 
            {
                closed(r, c, grid);
            }
        }
    }
    int closedIsland(vector<vector<int>>& grid) {
        // excluding zeroes on the corners they can't be closed island
        int m = grid.size();
        int n = grid[0].size();
        for(int i=0; i<m; i++)
        {
            if(grid[i][0] == 0) removeCorners(i, 0, grid);
            if(grid[i][n-1] == 0) removeCorners(i, n-1, grid);
        }
        for(int j=0; j<n; j++)
        {
            if(grid[0][j] == 0) removeCorners(0, j, grid);
            if(grid[m-1][j] == 0) removeCorners(m-1, j, grid);
        }
        int ans = 0;
        for(int i=1; i<m-1; i++) 
        {
            for(int j=1; j<n-1; j++)
            {
                if(grid[i][j] == 0) 
                {
                    ans++;
                    closed(i, j, grid);
                }
            }
        }
        return ans;
    }
};