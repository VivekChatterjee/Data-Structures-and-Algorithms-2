class Solution {
public:
    void dfs(int num, int &ans, vector<int> &vis, vector<vector<int>> &adj)
    {
        vis[num] = 1;
        for(auto i: adj[num])
        {
            if(!vis[abs(i)])
            {
                if(i > 0) ans++;
                dfs(abs(i), ans, vis, adj);
            }
        }
    }
    int minReorder(int n, vector<vector<int>>& con) {
        vector<vector<int>>adj(n);
        int ans = 0;
        vector<int>vis(n);
        for(auto i: con)
        {
            adj[i[0]].push_back(+i[1]);
            adj[i[1]].push_back(-i[0]);
        }
        dfs(0, ans, vis, adj);
        return ans;
    }
};