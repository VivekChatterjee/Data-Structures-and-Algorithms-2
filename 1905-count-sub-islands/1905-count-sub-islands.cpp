class Solution {
public:
    void dfs2(int i, int j, vector<vector<int>>& grid2, vector<vector<int>>& grid1, 
             bool &same)
    {
        int m = grid2.size();
        int n = grid2[0].size();
        if(i<0 || i>=m || j<0 || j>=n || grid2[i][j] == -1 || grid2[i][j] == 0) return;
        grid2[i][j] = -1;
        if(grid1[i][j] != 1) same = false;
        dfs2(i, j+1, grid2, grid1, same);
        dfs2(i+1, j, grid2, grid1, same);
        dfs2(i, j-1, grid2, grid1, same);
        dfs2(i-1, j, grid2, grid1, same);
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int m = grid1.size();
        int n = grid1[0].size();
        int ans = 0;
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                bool same = true;
                if(grid2[i][j] == 1)
                {
                    dfs2(i, j, grid2, grid1, same);
                    if(same) ans++;
                }
            }
        }
        return ans;
    }
};