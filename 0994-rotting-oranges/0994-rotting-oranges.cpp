class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size(), ans=0, fresh=0;
        queue<pair<int, pair<int, int>>>q;
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(grid[i][j] == 2) q.push({0, {i, j}});
                if(grid[i][j] == 1) fresh++;
            }
        }
        if(!fresh) return 0;
        vector<int>row={-1, 0, 1, 0}, col={0, -1, 0, 1};
        int ct=0;
        while(!q.empty())
        {
            int nn=q.size();
            for(int ii=0; ii<nn; ii++)
            {   
                int time=q.front().first, rr=q.front().second.first,            
                cc=q.front().second.second;
                grid[rr][cc]=2;
                ans=time;
                q.pop();
                for(int i=0; i<4; i++)
                {
                    int r=row[i]+rr, c=col[i]+cc;
                    if(r>=0 && r<m && c>=0 && c<n && grid[r][c] == 1) 
                    {
                        q.push({time+1, {r, c}});
                        grid[r][c] = 2;
                        ct++;
                    }
                }
            }
        }
        if(ct != fresh) return -1;
        return ans;
    }
};