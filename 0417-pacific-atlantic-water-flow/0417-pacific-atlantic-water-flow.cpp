class Solution {
public:
    vector<int>row={-1, 0, 1, 0}, col={0, -1,0,1};
    void water(int i, int j, vector<vector<int>> &mat, vector<vector<bool>> &vis)
    {
        int n=mat.size(), m=mat[0].size();
        vis[i][j]=1;
        for(int k=0; k<4; k++)
        {
            int r=row[k]+i, c=col[k]+j;
            if(r>=0 && r<n && c>=0 && c<m && mat[r][c]>=mat[i][j] && !vis[r][c])
            {
                water(r, c, mat, vis);
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& mat) {
        int n=mat.size(), m=mat[0].size();
        vector<vector<bool>> dp(n, vector<bool>(m));
        vector<vector<bool>> dp2(n, vector<bool>(m));
        for(int i=0; i<n; i++) if(!dp[i][0]) water(i, 0, mat, dp);
        for(int j=0; j<m; j++) if(!dp[0][j]) water(0, j, mat, dp);
        for(int i=0; i<n; i++) if(!dp2[i][m-1]) water(i, m-1, mat, dp2);
        for(int j=0; j<m; j++) if(!dp2[n-1][j]) water(n-1, j, mat, dp2);
        vector<vector<int>>ans;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(dp[i][j] && dp2[i][j])
                {
                    ans.push_back({i, j});
                }
            }
        }
        return ans;
    }
};