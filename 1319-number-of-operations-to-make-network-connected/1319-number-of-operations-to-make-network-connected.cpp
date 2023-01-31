class Solution {
public:
    void dfs(int i, vector<int>adj[], vector<int>&vis)
    {
        vis[i]=1;
        for(auto it: adj[i])
        {
            if(!vis[it]) dfs(it, adj, vis);
        }
    }
    int makeConnected(int n, vector<vector<int>>& con) {
        int size=con.size();
        if(size < n-1) return -1;
        vector<int>adj[n];
        for(auto i: con)
        {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        int ct=0;
        vector<int>vis(n);
        for(int i=0; i<n; i++)
        {
            if(!vis[i])
            {
                dfs(i, adj, vis);
                ct++;
            }
        }
        return ct-1;
    }
};