//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestXYDist(vector<vector<char>> grid, int n, int m) {
        queue<pair<int, pair<int, int>>>q;
        vector<vector<int>>vis(n, vector<int>(m));
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(grid[i][j]=='X')
                {
                    q.push({0, {i, j}});
                    vis[i][j]=1;
                }
            }
        }
        vector<int>v={-1,0,1,0,-1};
        while(!q.empty())
        {
            int dis=q.front().first;
            int i=q.front().second.first;
            int j=q.front().second.second;
            q.pop();
            if(grid[i][j] == 'Y')
            {
                return dis;
            }
            for(int k=0; k<4; k++)
            {
                int row=v[k]+i;
                int col=v[k+1]+j;
                if(row>=0 && row<n && col>=0 && col<m && !vis[row][col])
                {
                    vis[row][col]=1;
                    q.push({dis+1, {row, col}});
                }
            }
        }
        return -1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M;
        char ch;
        cin >> N >> M;

        vector<vector<char>> grid;

        for (int i = 0; i < N; i++) {
            vector<char> col;
            for (int i = 0; i < M; i++) {
                cin >> ch;
                col.push_back(ch);
            }
            grid.push_back(col);
        }

        Solution ob;
        cout << ob.shortestXYDist(grid, N, M) << endl;
    }
    return 0;
}
// } Driver Code Ends