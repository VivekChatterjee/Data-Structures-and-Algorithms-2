class Solution {
public:
    bool dfs(int node, bool isBlack, vector<vector<int>>& graph, vector<int>&vis)
    {
        vis[node] = (isBlack)? 1 : 2;
        for(auto it: graph[node])
        {
            if(!vis[it])
            {
                if(!dfs(it, !isBlack, graph, vis)) return 0;
            }
            if(vis[it] && vis[it] == vis[node]) return 0;
        }
        return 1;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>vis(n);
        // 0 if not visited
        // 1 for black
        // 2 for blue
        for(int i=0; i<n; i++)
        {
            if(!vis[i])
            {
                if(!dfs(i, 1, graph, vis)) return 0;
            }
        }
        return 1;
    }
};

