/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    void dfs(int id, vector<int>adj[], vector<int>&vis, int &ans, 
             unordered_map<int, int>&m)
    {
        ans += m[id];
        vis[id] = 1;
        for(auto i: adj[id])
        {
            if(!vis[i]) dfs(i, adj, vis, ans, m);
        }
    }
    int getImportance(vector<Employee*> employees, int id) {
        int n = 0;
        for(auto i: employees) n = max(n, i->id);
        vector<int>adj[n+1], vis(n+1);
        unordered_map<int, int>m;
        for(auto i: employees)
        {
            m[i->id] = i->importance;
            for(auto it: i->subordinates) adj[i->id].push_back(it);
        }
        int ans = 0;
        dfs(id, adj, vis, ans, m);
        return ans;
    }
};