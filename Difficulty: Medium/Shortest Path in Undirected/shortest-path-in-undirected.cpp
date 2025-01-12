//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

//Back-end complete function Template for C++


// } Driver Code Ends
class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& adj, int src) {
       vector<int>vis(adj.size());
       vector<int>dis(adj.size(), 1e9);
       queue<int>q;
       q.push(src);
       dis[src]=0;
       vis[src]=1;

       while(!q.empty()){
           int node=q.front();
           q.pop();

           for(auto nbr: adj[node]){
               if(!vis[nbr]){
                   q.push(nbr);
                   vis[nbr]=1;
                   if(dis[node]+1 < dis[nbr]){
                       dis[nbr]=dis[node]+1;
                   }
               }
           }
       }
       for(auto &i: dis){
           if(i==1e9) i=-1;
       }
       return dis;
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
            adj[v].push_back(u);
        }

        int src;
        cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(adj, src);

        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
        cout << "~\n";
    }
}

// } Driver Code Ends