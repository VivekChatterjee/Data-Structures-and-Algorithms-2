//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//Position this line where user code will be pasted.
class Solution {
  public:
    void dfs(int node, vector<vector<int>>&newAdj, vector<int>&vis){
        vis[node]=1;
        for(auto it: newAdj[node]){
            if(!vis[it]) dfs(it, newAdj, vis);
        }
    }
    void dfsFirst(int node, vector<vector<int>>&adj, vector<int>&vis, stack<int>&s){
        vis[node]=1;
        for(auto it: adj[node]){
            if(!vis[it]) dfsFirst(it, adj, vis, s);
        }
        s.push(node);
    }
    int kosaraju(vector<vector<int>> &adj) {
        vector<int>firstVis(adj.size());
        stack<int>s;
        for(int i=0; i<adj.size(); i++){
            if(!firstVis[i]) dfsFirst(i, adj, firstVis, s);
        }
        vector<vector<int>>newAdj(adj.size());
        vector<int>vis(newAdj.size());
        for(int i=0; i<adj.size(); i++){
            for(auto it: adj[i]){
                newAdj[it].push_back(i);
            }
        }
        int ans=0;
        while(!s.empty()){
            int i=s.top();
            s.pop();
            if(!vis[i])
            {
                ans++;
                dfs(i, newAdj, vis);
            }
        }
        return ans;
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
        cout << obj.kosaraju(adj) << "\n";

        // cout << "~"
        //      << "\n";
    }

    return 0;
}

// } Driver Code Ends