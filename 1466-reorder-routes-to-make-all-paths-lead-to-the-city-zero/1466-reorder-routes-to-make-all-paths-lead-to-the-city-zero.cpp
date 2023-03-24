class Solution {
public:
    int minReorder(int n, vector<vector<int>>& c) {
        vector<pair<int, int>>adj[n];
        // u -> v
        // +1 for direction towards 0 (v -> u)
        // -1 for direction away from 0 (u -> v)
        for(auto i: c)
        {
            adj[i[0]].push_back({i[1], -1});
            adj[i[1]].push_back({i[0], +1});
        }
        vector<int>vis(n);
        queue<int>q;
        int ans=0;
        q.push(0);
        vis[0]=1;
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            for(auto &[nbr, dir]: adj[node])
            {
                if(!vis[nbr])
                {
                    if(dir<0)
                    {
                        ans+=-dir;
                    }
                    vis[nbr]=1;
                    q.push(nbr);
                }
            }
        }
        return ans;
    }
};