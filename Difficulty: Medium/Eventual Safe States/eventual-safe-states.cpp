//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    bool isCycle(vector<int>adj[], vector<int>&vis, vector<int>&nodes, int node){
        vis[node]=2;
        nodes[node]=0;
        for(auto i: adj[node]){
            if(vis[i]==0){
                if(isCycle(adj, vis, nodes, i)==true)
                {
                    nodes[i]=0;
                    return true;
                }
            }
            else if(vis[i]==2) {
                nodes[i]=0;
                return true;
            }
        }
        nodes[node]=1;
        vis[node]=1;
        return false;
    }
    vector<int> eventualSafeNodes(int v, vector<int> adj[]) {
        vector<int>nodes(v);
        vector<int>safeNodes;
        vector<int>vis(v);
        // 0 for unvisited
        // 1 for visited only
        // 2 for visited and pathvisited both
        for(int i=0; i<v; i++){
            if(vis[i]==0)
                isCycle(adj, vis, nodes, i);
        }
        for(int i=0; i<v; i++){
            if(nodes[i]) safeNodes.push_back(i);
        }
        return safeNodes;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int V, E;
        cin >> V >> E;
        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    
cout << "~" << "\n";
}
}

// } Driver Code Ends