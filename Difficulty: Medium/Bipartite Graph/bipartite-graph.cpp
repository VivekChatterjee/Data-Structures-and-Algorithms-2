//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool dfs(vector<vector<int>>& adj, vector<int>&color, int node, int col){
        color[node]=col;
        for(auto i: adj[node]){
            if(color[i]==-1){
                if(dfs(adj, color, i, !col) == false) return false;
            }
            else if(color[i]==col) return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& adj) {
        vector<int>color(adj.size(), -1);
        for(int i=0; i<adj.size(); i++){
            if(color[i]==-1 && dfs(adj, color, i, 0) == false) return false;
        }
        return true;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj(V);
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isBipartite(adj);
        if (ans)
            cout << "true\n";
        else
            cout << "false\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends