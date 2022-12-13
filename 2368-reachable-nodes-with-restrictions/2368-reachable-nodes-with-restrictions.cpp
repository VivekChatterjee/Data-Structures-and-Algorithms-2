class Solution {
public:
    int ans = 0;
    void totalReach(int num, vector<int>&vis, vector<vector<int>>&adj)
    {
        vis[num] = 1;
        ans++;
        for(auto i: adj[num])
        {
            if(!vis[i]) totalReach(i, vis, adj);
        }
    }
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& res) {
        vector<vector<int>>adj(n);
        for(auto i: edges)
        {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        vector<int>vis(n);
        for(int i: res) vis[i] = 1;
        totalReach(0, vis, adj);
        return ans;
    }
};