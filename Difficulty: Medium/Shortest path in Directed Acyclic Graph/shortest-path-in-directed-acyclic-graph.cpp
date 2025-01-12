//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    void topoSort(vector<pair<int, int>>adj[], vector<int>&vis, stack<int>&st, int node)
    {
        vis[node]=1;
        for(auto it: adj[node]){
            if(!vis[it.first]) topoSort(adj, vis, st, it.first);
        }
        st.push(node);
    }
    vector<int> shortestPath(int v, int e, vector<vector<int>>& edges) {
        vector<pair<int, int>>adj[v];
        for(auto edge: edges){
            adj[edge[0]].push_back({edge[1], edge[2]});
        }
        stack<int>st;
        vector<int>vis(v);
        for(int i=0; i<v; i++){
            if(!vis[i]) topoSort(adj, vis, st, i);
        }
        vector<int>dis(v, 1e9);
        dis[0]=0;
        while(!st.empty()){
            int top=st.top();
            st.pop();
            
            for(auto it: adj[top]){
                int node=it.first;
                int wt=it.second;
                if(dis[top]+wt < dis[node]){
                    dis[node]=dis[top]+wt;
                }
            }
        }
        for(auto &it: dis){
            if(it==1e9) it=-1;
        }
        return dis;
    }
    
    
    
    
    
    
    
    
    
    
    
    
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends