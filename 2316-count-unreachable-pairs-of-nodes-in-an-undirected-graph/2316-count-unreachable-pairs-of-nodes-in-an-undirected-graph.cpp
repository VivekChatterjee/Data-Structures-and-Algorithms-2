#define ll long long
class Solution {
public:
    void dfs(int &cur, int i, vector<int>adj[], vector<int>&vis)
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
        vector<ll>nodes, pre;
        vector<int>adj[n];
        for(auto i: edges)
        {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        vector<int>vis(n);
        for(int i=0; i<n; i++)
        {
            if(!vis[i])
            {
                int cur=0;
                dfs(cur, i, adj, vis);
                nodes.push_back(cur*1LL);
            }
        }
        n=nodes.size();
        pre.push_back(nodes[0]);
        for(int i=1; i<n; i++)
        {
            pre.push_back(pre[i-1]+nodes[i]);
        }
        ll last=pre[n-1];
        ll ans=0;
        for(int i=0; i<n-1; i++)
        {
            ans+=(last-pre[i])*nodes[i];
        }
        return ans;
    }
};