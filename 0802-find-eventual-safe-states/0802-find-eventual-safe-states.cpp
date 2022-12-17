class Solution {
public:
    bool dfs(int num, vector<vector<int>>& graph, vector<int> &vis)
    {
        vis[num] = 1;
        for(auto i: graph[num])
        {
            if(!vis[i])
            {
                if (dfs(i, graph, vis))
                {
                    vis[i] = 1;
                    return 1;
                }                
            }
            else if(vis[i] == 1) return 1;
        }
        vis[num] = -1;
        return 0;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>vis(n), ans;
        // 0 for not visited
        // -1 means safe and visited
        // 1 means cycle present and visited
        for(int i=0; i<n; i++)
        {
            if(!vis[i]) dfs(i, graph, vis);
        }
        for(int i=0; i<n; i++)
        {
            if(vis[i] == -1) ans.push_back(i);
        }
        return ans;
    }
};