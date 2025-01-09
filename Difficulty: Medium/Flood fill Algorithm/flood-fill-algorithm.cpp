//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    void dfs(vector<vector<int>>& image, vector<vector<int>>& vis, int sr, int sc,
            int toChange, int newColor) {
        if(sr<0 || sc<0 || sr>=vis.size() || sc>=vis[0].size() || image[sr][sc]!=toChange || vis[sr][sc])
        return;
        vis[sr][sc]=1;
        image[sr][sc]=newColor;
        dfs(image, vis, sr+1, sc, toChange, newColor);
        dfs(image, vis, sr, sc+1, toChange, newColor);
        dfs(image, vis, sr-1, sc, toChange, newColor);
        dfs(image, vis, sr, sc-1, toChange, newColor);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int newColor) {
        int m=image.size();
        int n=image[0].size();
        int toChange = image[sr][sc];
        vector<vector<int>>vis(m, vector<int>(n));
        dfs(image, vis, sr, sc, toChange, newColor);
        return image;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> image(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                cin >> image[i][j];
        }
        int sr, sc, newColor;
        cin >> sr >> sc >> newColor;
        Solution obj;
        vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
        for (auto i : ans) {
            for (auto j : i)
                cout << j << " ";
            cout << "\n";
        }

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends