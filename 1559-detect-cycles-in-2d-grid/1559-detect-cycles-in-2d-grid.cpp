class Solution {
public:
    vector<int>row={-1, 0, 1, 0}, col={0, -1, 0, 1};
    bool cycle(int pari, int parj, int i, int j, int len, vector<vector<char>>& grid, vector<vector<int>>& vis)
    {
        int m=grid.size(), n=grid[0].size();
        vis[i][j]=1;
        for(int k=0; k<4; k++)
        {
            int r=row[k]+i, c=col[k]+j;
            if(r>=0 && r<m && c>=0 && c<n && (r!=pari 
               || c!=parj) && grid[r][c]==grid[i][j])
            {
                if(!vis[r][c]) 
                {
                    if(cycle(i, j, r, c, len+1, grid, vis)) return 1;
                }
                else if(vis[r][c] && len+1>=4) return 1;
            }
        }
        return 0;
    }
    bool containsCycle(vector<vector<char>>& grid) {
        int m=grid.size(), n=grid[0].size();
        vector<vector<int>>vis(m, vector<int>(n));
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(!vis[i][j]) 
                {
                    if(cycle(-1, -1, i, j, 0, grid, vis)) return 1;
                }
            }
        }
        return 0;
    }
};