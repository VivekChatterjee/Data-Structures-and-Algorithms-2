class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<pair<int, pair<int, int>>>q;
        int m=mat.size();
        int n=mat[0].size();
        vector<vector<int>>ans(m, vector<int>(n, -1));
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(mat[i][j] == 0) 
                {
                    q.push({0, {i, j}});
                    ans[i][j]=0;
                }
            }
        }
        vector<int>row={-1, 0, 1, 0}, col={0, -1, 0, 1};
        while(!q.empty())
        {
            int dis=q.front().first;
            int ii=q.front().second.first;
            int jj=q.front().second.second;
            q.pop();
            for(int i=0; i<4; i++)
            {
                int rr=row[i]+ii;
                int cc=col[i]+jj;
                if(rr>=0 && rr<m && cc>=0 && cc<n)
                {
                    if(ans[rr][cc] == -1)
                    {
                        ans[rr][cc]=dis+1;
                        q.push({dis+1, {rr, cc}});
                    }
                }
            }
        }
        return ans;
    }
};