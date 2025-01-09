//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void dfs(vector<vector<int>>& grid, vector<vector<int>>& vis, 
    vector<pair<int, int>>&graph, int i, int j, int baser, int basec){
        vis[i][j]=1;
        graph.push_back({i-baser, j-basec});
        vector<int>dir={-1,0,1,0,-1};
        int m=grid.size();
        int n=grid[0].size();
        for(int cur=0; cur<dir.size()-1; cur++){
            int row=i+dir[cur];
            int col=j+dir[cur+1];
            if(row>=0 && col>=0 && row<m && col<n && grid[row][col] && !vis[row][col]){
                dfs(grid, vis, graph, row, col, baser, basec);   
            }
        }
    }
    int countDistinctIslands(vector<vector<int>>& grid) {
        // leftmost 1st "1" is considered as base
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>vis(m, vector<int>(n));
        set<vector<pair<int, int>>>graphs;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] && !vis[i][j])
                {
                    vector<pair<int, int>>graph;
                    dfs(grid, vis, graph, i, j, i, j);
                    graphs.insert(graph);
                }
            }
        }
        return graphs.size();
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    
cout << "~" << "\n";
}
}
// } Driver Code Ends