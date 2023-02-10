class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n=grid[0].size();
        queue<pair<int, int>>q;
        vector<vector<int>>vis(n, vector<int>(n));
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(grid[i][j]==1)
                {
                    q.push({i, j});
                    vis[i][j]=1;
                }
            }
        }
        int ans=0;
        vector<int>row={-1,0,1,0}, col={0,-1,0,1};
        while(!q.empty())
        {
            int sz=q.size();
            for(int i=0; i<sz; i++)
            {
                int rr=q.front().first, cc=q.front().second;
                q.pop();
                for(int k=0; k<4; k++)
                {
                    int r=row[k]+rr, c=col[k]+cc;
                    if(r>=0 and r<n and c>=0 and c<n)
                    {
                        if(!vis[r][c])
                        {
                            vis[r][c]=1;
                            q.push({r, c});
                        }
                    }
                }
            }
            if(q.empty()) break;
            ans++;
        }
        return (ans==0)? -1 : ans;
    }
};