#define ll long long
class Solution {
public:
    void dfs(ll &cur, int i, vector<int>adj[], vector<int>&vis)
    {
        vis[i]=1;
        cur++;
        for(auto it: adj[i])
        {
            if(!vis[it])
            {
                dfs(cur, it, adj, vis);
            }
        }
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<int>adj[n];
        for(auto i: edges)
        {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        vector<int>vis(n);
        ll ans=n*1LL*((n-1)*1LL)/2;
        for(int i=0; i<n; i++)
        {
            if(!vis[i])
            {
                ll cur=0;
                dfs(cur, i, adj, vis);
                ans-=(cur*(cur-1)/2);
            }
        }
        return ans;
    }
};