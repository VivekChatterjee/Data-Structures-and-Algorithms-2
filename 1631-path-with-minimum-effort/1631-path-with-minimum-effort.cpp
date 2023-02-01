#define pii pair<int, pair<int, int>>
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m=heights.size(), n=heights[0].size(), ans=INT_MAX;
        priority_queue<pii, vector<pii>, greater<pii>>p; 
        // {{curEffort, {row, col}}
        p.push({0, {0, 0}});
        vector<int>row={-1, 0, 1 , 0}, col={0, -1, 0, 1};
        vector<vector<int>>dis(m, vector<int>(n, 1e7));
        while(!p.empty())
        {
            int cur=p.top().first;
            int i=p.top().second.first;
            int j=p.top().second.second;
            if(i==m-1 && j==n-1) return ans=cur;
            p.pop();
            for(int adj=0; adj<4; adj++)
            {
                int r=row[adj]+i, c=col[adj]+j;
                if(r>=0 && r<m && c>=0 && c<n)
                {
                    int ab=max(cur, abs(heights[r][c]-heights[i][j]));
                    if(ab<dis[r][c])
                    {
                        dis[r][c]=ab;
                        p.push({ab, {r, c}});
                    }
                }
            }
        }
        return ans;        
    }
};