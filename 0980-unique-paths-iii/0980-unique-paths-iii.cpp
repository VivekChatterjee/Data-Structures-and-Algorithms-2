class Solution {
public:
    int ans = 0;
    void paths(int i, int j, vector<vector<int>>& grid, int non)
    {
        int m = grid.size();
        int n = grid[0].size(); 
        if(i<0 || j<0 || i>=m || j>=n || grid[i][j] == -1) return;
        if(grid[i][j] == 2) 
        {
            if(non == 0) ans++;
            return;
        }
        int num = grid[i][j];
        grid[i][j] = -1;
        if(num == 0) non--;
        paths(i, j+1, grid, non);
        paths(i, j-1, grid, non);
        paths(i-1, j, grid, non);
        paths(i+1, j, grid, non);
        grid[i][j] = num;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int srci, srcj, non = 0;
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(grid[i][j] == 1) srci = i, srcj = j;
                if(grid[i][j] == 0) non++;
            }
        }
        paths(srci, srcj, grid, non);
        return ans;
    }
};