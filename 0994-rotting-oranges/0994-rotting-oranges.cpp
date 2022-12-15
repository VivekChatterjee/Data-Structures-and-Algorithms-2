class Solution {
public:
    int orangesRotting(vector<vector<int>> &grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<pair<int,int>, int>> q; // {{index, index}, time}
        int fresh=0; 
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==2)
                {
                    q.push({{i, j}, 0});
                }
                if(grid[i][j] == 1)
                    fresh++;
            }
        }
        if(fresh == 0) return 0;
        int ans=0;
        vector<int>row = {-1,0,+1,0};
        vector<int>col = {0,-1,0,+1};
        while(!q.empty())
        {
            int size = q.size();
            for(int i = 0; i < size; i++)
            {
                int rr = q.front().first.first;
                int cc = q.front().first.second;
                int t = q.front().second;
                q.pop();
                for(int del = 0; del < 4; del++)
                {
                    int r = rr + row[del];
                    int c = cc + col[del];
                    if(r>=0 && r<m && c>=0 && c<n && grid[r][c] == 1)
                    {
                        grid[r][c] = 2;
                        q.push({{r,c}, t+1});
                        ans = max(ans, t+1);
                        fresh--;
                    }
                }
            }
        }
        return (fresh > 0)? -1 : ans;
    }
};