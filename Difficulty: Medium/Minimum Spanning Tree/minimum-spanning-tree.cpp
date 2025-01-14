//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int v, vector<vector<int>> adj[]) {
        int sum=0;
        vector<pair<int, int>>mst;
        vector<int>vis(v);
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>p; 
        // distance, node, parent
        p.push({0, 0, -1});
        while(!p.empty()){
            vector<int>v=p.top();
            p.pop();
            
            if(v[2]!=-1 && !vis[v[1]]){
                mst.push_back({v[2], v[1]});
                sum+=v[0];
            }
            
            vis[v[1]]=1;
            for(auto it: adj[v[1]]){
                // cout<<v[1]<<" " <<it[0]<< " "<<it[1]<< " "<<it[2]<<endl;
                if(!vis[it[0]]){
                    p.push({it[1], it[0], v[1]});
                }
            }
        }
        return sum;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i = 0;
        while (i++ < E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1, t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }

        Solution obj;
        cout << obj.spanningTree(V, adj) << "\n";

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends