class Solution {
public:
    int minimumVisitedCells(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size(), ans=0;
        queue<pair<int, int>>q;
        q.push({0, 0});
        vector<vector<int>>vis(m, vector<int>(n));
        vis[0][0]=1;
        while(!q.empty())
        {
            int size=q.size();
            while(size--)
            {
                auto [r, c]=q.front();
                q.pop();
                if(r==m-1 && c==n-1) return ans+1;
                vis[r][c]=1;
                for(int k=min(grid[r][c], n-c); k>=0; k--)
                {
                    if(c+k<n && !vis[r][c+k])
                    {
                        q.push({r, c+k});
                        vis[r][c+k]=1;
                    }
                }
                for(int k=min(grid[r][c], m-r); k>=0; k--)
                {
                    if(r+k<m && !vis[r+k][c])
                    {
                        q.push({r+k, c});
                        vis[r+k][c]=1;
                    }
                }
            }
            ans++;
        }
        return -1;
    }
};