class Solution {
public:
    bool dfs(int s, int d, vector<int>adj[], vector<int>&vis)
    {
        vis[s] = 1;
        if(s == d) return 1;
        for(auto i: adj[s])
        {
            if(!vis[i]) if(dfs(i, d, adj, vis)) return 1;
        }
        return 0;
    }
    bool validPath(int n, vector<vector<int>>& edges, int s, int d) {
        vector<int>adj[n], vis(n);
        for(auto i: edges)
        {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        return dfs(s, d, adj, vis);
    }
};