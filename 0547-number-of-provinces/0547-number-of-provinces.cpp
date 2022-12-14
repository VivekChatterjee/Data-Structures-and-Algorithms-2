class Solution {
public:
    void dfs(vector<vector<int>>& c, int j, vector<int>&vis)
    {
        int n = c.size();
        vis[j] = 1;
        for(int i=0; i<c[j].size();i++)
        {
            if(c[j][i] == 1 && !vis[i]) dfs(c, i, vis);
        }
    }
    int findCircleNum(vector<vector<int>>& c) {
        int n=c.size();
        int ans=0;
        vector<int>vis(n);
        for(int i=0; i<n; i++)
        {
            if(!vis[i])
            {
                ans++;
                dfs(c,i, vis);
            }
        }
        return ans;
    }
};