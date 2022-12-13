class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<int>>adj(n+2);
        int ans = -1;
        for(auto i: edges)
        {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
            if(adj[i[0]].size() == n)
            {
                ans = i[0];
                break;
            }
            if(adj[i[1]].size() == n)
            {
                ans = i[1];
                break;
            }
        }
        return ans;
    }
};