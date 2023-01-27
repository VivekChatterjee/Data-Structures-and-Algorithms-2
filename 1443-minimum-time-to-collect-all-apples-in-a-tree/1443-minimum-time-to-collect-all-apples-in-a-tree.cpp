class Solution {
public:
    int time(int i, vector<int>adj[], vector<bool>&hasApple, vector<int>&vis)
    {
        vis[i]=1;
        int ct=0;
        for(auto node: adj[i])
        {
            if(!vis[node])
            {
                ct += time(node, adj, hasApple, vis);
            }
        }
        if(i == 0)
        {
            return ct;
        }
        else
        {
            if(hasApple[i])
            {
                if(ct > 0) return ct+2;
                else return 2;
            }
            else 
            {
                if(ct > 0) return ct+2;
                else return 0;
            }
        }
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<int>adj[n], vis(n);
        for(auto i: edges)
        {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        return time(0, adj, hasApple, vis);
    }
};