class Solution {
public:
    void dfs(int i, vector<int> &vis, vector<int> adj[], int &count)
    {
        vis[i] = 1;
        count++;
        for(auto num: adj[i])
        {
            if(!vis[num]) dfs(num, vis, adj, count);
        }        
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<int>adj[n], vis(n);
        for(int i=0; i<n; i++)
        {
            for(auto j: rooms[i])
            {
                adj[i].push_back(j);
            }
        }
        int count = 0;
        dfs(0, vis, adj, count);
        return count == n;        
    }
};