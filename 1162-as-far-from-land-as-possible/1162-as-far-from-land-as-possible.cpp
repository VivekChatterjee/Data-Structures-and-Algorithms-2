#define pii pair<int, int>
class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<pii>q; // {distance, {row, col}}
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(grid[i][j] == 1)
                {
                    q.push({i-1, j});
                    q.push({i+1, j});
                    q.push({i, j-1});
                    q.push({i, j+1});
                }
            }
        }
        int ans = 0;
        vector<int>row = {0, -1, 0, 1}, col = {-1, 0, 1, 0};
        while(!q.empty())
        {
            int size = q.size();
            ans++;
            for(int i=0; i<size; i++)
            {
                int r = q.front().first;
                int c = q.front().second;
                q.pop();
                if(r>=0 && r<n && c>=0 && c<n && grid[r][c] == 0)
                {
                    grid[r][c] = ans;
                    q.push({r-1, c});
                    q.push({r+1, c});
                    q.push({r, c-1});
                    q.push({r, c+1});
                }
            }
        }
        return (ans == 1)? -1 : ans - 1 ;
    }
};