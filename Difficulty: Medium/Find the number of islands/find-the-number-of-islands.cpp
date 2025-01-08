//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    void dfs(vector<vector<char>>& grid, vector<vector<int>>&vis, int i, int j){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j] == '0' || vis[i][j]) return;
        vis[i][j]=1;
        dfs(grid, vis, i, j+1);
        dfs(grid, vis, i+1, j);
        dfs(grid, vis, i+1, j+1);
        dfs(grid, vis, i-1, j+1);
        dfs(grid, vis, i-1, j-1);
        dfs(grid, vis, i+1, j-1);
        dfs(grid, vis, i-1, j);
        dfs(grid, vis, i, j-1);
    }
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int num=0;
        vector<vector<int>>vis(m, vector<int>(n));
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[i].size(); j++){
                if(grid[i][j] == '1' && !vis[i][j])
                {
                    num++;
                    dfs(grid, vis, i, j);
                }
            }
        }
        return num;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends