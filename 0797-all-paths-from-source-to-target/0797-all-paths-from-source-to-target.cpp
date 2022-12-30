class Solution {
public:
    vector<vector<int>>ans;
    int n;
    void dfs(int num, vector<vector<int>>& graph, vector<int> path)
    {
        path.push_back(num);
        if(num == n-1) ans.push_back(path);
        for(auto i: graph[num]) dfs(i, graph, path);
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        n = graph.size();
        vector<int>path;
        dfs(0, graph, path);
        return ans;
    }
};