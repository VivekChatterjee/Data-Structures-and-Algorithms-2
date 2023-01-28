class Solution {
public:
    int time(int i, int par, vector<int>adj[], vector<bool>&hasApple)
    {
        int ct=0;
        for(auto node: adj[i])
        {
            if(node != par)
            {
                ct += time(node, i, adj, hasApple);
            }
        }
        if(i == 0) return ct;
        else
        {
            if(ct > 0) return ct+2;
            else if(hasApple[i]) return 2;
            else return 0;
        }
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<int>adj[n];
        for(auto i: edges)
        {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        return time(0, -1, adj, hasApple);
    }
};