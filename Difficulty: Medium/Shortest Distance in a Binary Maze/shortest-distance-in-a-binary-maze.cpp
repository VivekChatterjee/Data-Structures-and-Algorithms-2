//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

#define pipii pair<int, pair<int, int>>
class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> s,
        pair<int, int> d) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>dis(m, vector<int>(n, 1e9));
        if(s.first == d.first && s.second == d.second) return 0;

        // distance, row, col
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>p;
        if(!grid[d.first][d.second] || !grid[s.first][s.second]) return -1;
        grid[s.first][s.second]=0;
        vector<int>dir={-1,0,1,0,-1};
        
        p.push({0, s.first, s.second});
        while(!p.empty()){
            vector<int>v=p.top();
            p.pop();
            grid[v[1]][v[2]]=0;
            for(int i=0; i<dir.size()-1; i++){
                int r=v[1]+dir[i];
                int c=v[2]+dir[i+1];
                
                if(r>=0 && c>=0 && r<m && c<n && grid[r][c]){
                    if(v[0]+1 < dis[r][c]){
                        dis[r][c]=v[0]+1;
                        p.push({v[0]+1, r, c});
                    }
                }
            }
        }
        if(dis[d.first][d.second]==1e9) return -1;
        return dis[d.first][d.second];
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

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    
cout << "~" << "\n";
}
}

// } Driver Code Ends