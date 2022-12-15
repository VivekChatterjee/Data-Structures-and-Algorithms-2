class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& grid) {
        int m = grid.size();
	    int n = grid[0].size();
	    vector<vector<int>>ans(m, vector<int>(n)), vis(m, vector<int>(n));
	    queue<pair<pair<int,int>, int>>q;
	    for(int i=0; i<m; i++)
	    {
	        for(int j=0; j<n; j++)
	        {
	            if(grid[i][j] == 0)
	            {
	                vis[i][j] = 1;
	                q.push({{i, j}, 0});
	            }
	        }
	    }
	    vector<int>row = {-1, 0, 1, 0};
	    vector<int>col = {0, -1, 0, 1};
	    while(!q.empty())
	    {
	        int size = q.size();
	        while(size--)
	        {
    	       int r= q.front().first.first;
    	       int c = q.front().first.second;
    	       int dis = q.front().second;
    	       q.pop();
    	       ans[r][c] = dis;
    	       for(int i=0; i<4; i++)
    	       {
    	            int rr = r+row[i];
    	            int cc = c+col[i];
    	            if(rr>=0 && rr<m && cc>=0 && cc<n && !vis[rr][cc])
    	            {
    	                vis[rr][cc] = 1;
    	                q.push({{rr, cc}, dis+1});
                    }
                }
	        }
	    }
	    return ans;
	}
};