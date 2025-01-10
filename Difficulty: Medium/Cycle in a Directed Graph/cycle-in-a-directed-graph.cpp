//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool isCycle(vector<vector<int>> adj, vector<int>&vis, vector<int>&pathVis,
    int node){
        if(pathVis[node]) return true;
        vis[node]=1;
        pathVis[node]=1;
        for(auto i: adj[node]){
            if(vis[i] && pathVis[i]) return true;
            if(!vis[i]){
                if(isCycle(adj, vis, pathVis, i)==true) return true;
            }
        }
        pathVis[node]=0;
        return false;
    }
    bool isCyclic(int v, vector<vector<int>> adj) {
        vector<int>vis(v);
        vector<int>pathVis(v);
        for(int i=0; i<v; i++){
            if(!vis[i] && isCycle(adj, vis, pathVis, i)) return true;
        }
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<vector<int>> adj(V);

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends