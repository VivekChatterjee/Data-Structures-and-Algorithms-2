class Solution {
public:
    bool isCycle(int col, int num, vector<int>adj[], vector<int> &vis)
    {
        vis[num] = col;
        for(auto i: adj[num])
        {
            if(vis[i] != -1 && vis[i] == vis[num]) return 1;
            else if(vis[i] == -1) if(isCycle(!col, i, adj, vis)) return 1;
        }
        return 0;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dis) {
        vector<int>adj[n+1];
        for(auto i: dis)
        {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        vector<int>vis(n+1, -1);
        for(int i=1; i<=n; i++)
        {
            if(vis[i] == -1) if(isCycle(1, i, adj, vis)) return 0;
        }
        return 1;
    }
};