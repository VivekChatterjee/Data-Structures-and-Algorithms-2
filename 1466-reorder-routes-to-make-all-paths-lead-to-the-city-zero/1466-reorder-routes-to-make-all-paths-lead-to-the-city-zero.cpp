class Solution {
public:
    void dfs(int num, int &ans, vector<int> &vis, vector<vector<int>> &adj, vector<vector<int>> &real)
    {
        vis[num] = 1;
        for(auto i: adj[num])
        {
            if(!vis[i])
            {
                auto it = find(real[num].begin(), real[num].end(), i);
                if(it != real[num].end()) ans++;
                dfs(i, ans, vis, adj, real);
            }
        }
    }
    int minReorder(int n, vector<vector<int>>& con) {
        vector<vector<int>>adj(n), real(n);
        int ans = 0;
        vector<int>vis(n);
        for(auto i: con)
        {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
            real[i[0]].push_back(i[1]);
        }
        dfs(0, ans, vis, adj, real);
        return ans;
    }
};