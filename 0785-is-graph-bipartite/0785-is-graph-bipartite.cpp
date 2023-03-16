class Solution {
public:
    int red=1, black=2;
    bool bipartite(int node, bool isBlack, vector<vector<int>>& graph, vector<int>& vis)
    {
        int color = (isBlack) ? black : red;
        vis[node] = color;
        for(auto &it : graph[node])
        {
            if(!vis[it])
            {
                if(!bipartite(it, !isBlack, graph, vis))
                {
                    return 0;
                }
            }
            else if(vis[it] && vis[it] == color)
            {
                return 0;
            }
        }
        return 1;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>vis(n);
        for(int i=0; i<n; i++)
        {
            if(!vis[i])
            {
                if(!bipartite(i, 1, graph, vis))
                    return 0;
            }
        }
        return 1;
    }
};