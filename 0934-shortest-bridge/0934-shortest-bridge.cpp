class Solution {
public:
    void dfsPush(int i, int j, vector<vector<int>>& grid, queue<pair<int, int>>&q)
    {
        int n=grid.size();
        if(i<0 || i>=n || j<0 || j>=n || grid[i][j]==0 || grid[i][j]==2)
            return;
        q.push({i, j});
        grid[i][j]=2;
        dfsPush(i+1, j, grid, q);
        dfsPush(i-1, j, grid, q);
        dfsPush(i, j+1, grid, q);
        dfsPush(i, j-1, grid, q);
    }
    int shortestBridge(vector<vector<int>>& grid) {
        int n=grid.size(), found=0;
        queue<pair<int, int>>q;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(grid[i][j] == 1)
                {
                    dfsPush(i, j, grid, q);
                    found=1;
                    break;                    
                }
            }
            if(found) break;
        }
        int cur=0, ans=1e8;
        vector<int>dir={1,0,-1,0,1};
        while(!q.empty())
        {
            int sz=q.size();
            while(sz--)
            {
                int i=q.front().first;
                int j=q.front().second;
                q.pop();
                for(int k=0; k<4; k++)
                {
                    int r=i+dir[k];
                    int c=j+dir[k+1];
                    if(r>=0 && r<n && c>=0 && c<n)
                    {
                        if(grid[r][c]==0)
                        {
                            grid[r][c]=2;
                            q.push({r, c});
                        }
                        else if(grid[r][c] == 1)
                            ans=min(ans, cur);
                    }
                }
            }
            if(!q.empty()) cur++;
        }
        return min(cur, ans);
    }
};