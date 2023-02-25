//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void dfs(int i, int &num, vector<vector<int>>& adj, vector<int>&vis, vector<int>&compo)
    {
        vis[i]=1;
        num++;
        for(auto it: adj[i])
        {
            if(!vis[it])
            {
                dfs(it, num, adj, vis, compo);
            }
        }
    }
    int findNumberOfGoodComponent(int v, vector<vector<int>>& adj) {
        vector<int>vis(v+1), compo(v+1);
        for(int i=1; i<=v; i++)
        {
            compo[i]=adj[i].size();
        }
        int ans=0;
        for(int i=1; i<=v; i++)
        {
            if(!vis[i])
            {
                int ct=0;
                dfs(i, ct, adj, vis, compo);
                bool pos=(compo[i]==ct-1);
                for(auto it: adj[i])
                {
                    pos&=(compo[it]==ct-1);
                }
                if(pos) ans++;
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
        int E, V;
        cin >> E >> V;
        vector<vector<int>> adj(V + 1, vector<int>());
        for (int i = 0; i < E; i++) {
            int u, v;

            cin >> u >> v;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;

        int res = obj.findNumberOfGoodComponent(V, adj);
        cout << res << "\n";
    }
    return 0;
}
// } Driver Code Ends