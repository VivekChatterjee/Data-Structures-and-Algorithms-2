class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<pair<int, int>>adj[n+1];
        for(auto it: roads)
        {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        vector<int>vis(n+1);
        int ans=1e8;
        queue<int>q;
        q.push(1);
        vis[1]=1;
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            for(auto &[nbr, dis]: adj[node])
            {
                ans=min(ans, dis);
                if(!vis[nbr])
                {
                    vis[nbr]=1;
                    q.push(nbr);
                }
            }
        }
        return ans;
    }
};