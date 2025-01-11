//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    void dfs(vector<vector<int>>& adj, vector<int>&vis, stack<int>&st, int node){
        vis[node]=1;
        for(auto it: adj[node]){
            if(!vis[it]) dfs(adj, vis, st, it);
        }
        st.push(node);
    }
    void kahn(vector<vector<int>>& adj, vector<int>&ans){
        queue<int>q;
        vector<int>indeg(adj.size());
        for(auto it: adj){
            for(int i: it){
                indeg[i]++;
            }
        }
        for(int i=0; i<adj.size(); i++){
            if(!indeg[i]) q.push(i);
        }
        while(!q.empty()){
            int top=q.front();
            q.pop();
            ans.push_back(top);
            for(auto it: adj[top]){
                indeg[it]--;
                if(!indeg[it]) q.push(it);
            }
        }
    }
    vector<int> topologicalSort(vector<vector<int>>& adj) {
        // stack<int>st;
        // vector<int>vis(adj.size());
        // for(int i=0; i<adj.size(); i++){
        //     if(!vis[i]) dfs(adj, vis, st, i);
        // }
        // vector<int>ans;
        // while(!st.empty()){
        //     ans.push_back(st.top());
        //     st.pop();
        // }
        // return ans;
        vector<int>ans;
        kahn(adj, ans);
        return ans;
    }
};

//{ Driver Code Starts.

/*  Function to check if elements returned by user
 *   contains the elements in topological sorted form
 *   V: number of vertices
 *   *res: array containing elements in topological sorted form
 *   adj[]: graph input
 */
int check(int V, vector<int> &res, vector<vector<int>> adj) {

    if (V != res.size())
        return 0;

    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v])
                return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> N >> E;
        int u, v;

        vector<vector<int>> adj(N);

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> res = obj.topologicalSort(adj);

        cout << check(N, res, adj) << endl;

        cout << "~"
             << "\n";
    }

    return 0;
}
// } Driver Code Ends