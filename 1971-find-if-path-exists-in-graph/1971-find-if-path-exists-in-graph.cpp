class Solution {
public:
    bool isPath(vector<int>&vis, vector<vector<int>>&adj, int &s, int &d)
    {
        vis[s] = 1;
        if(s == d) return 1;
        for(auto i: adj[s])
        {
            if(!vis[i] && isPath(vis, adj, i, d)) return 1; 
        }
        return 0;
    }
    bool validPath(int n, vector<vector<int>>& edges, int s, int d) {
        vector<vector<int>>adj(n+1);
        for(auto i: edges)
        {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        vector<int>vis(n);
        return isPath(vis, adj, s, d);
    }
};