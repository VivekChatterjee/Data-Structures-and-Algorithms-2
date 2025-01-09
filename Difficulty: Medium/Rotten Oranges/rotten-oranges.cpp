//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int orangesRotting(vector<vector<int>>& mat) {
        queue<pair<int,int>>q;
        int time=0, freshOranges=0;
        int m=mat.size();
        int n=mat[0].size();
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(mat[i][j]==2) q.push({i, j});
                if(mat[i][j]==1) freshOranges++;
            }
        }
        if(freshOranges==0) return time;
        if(q.empty()) return -1;
        vector<int>dir={-1,0,1,0,-1};
        while(!q.empty()){
            int cur=q.size();
            time++;
            for(int i=0; i<cur; i++){
                pair<int, int>ind=q.front();
                q.pop();
                int r=ind.first;
                int c=ind.second;
                for(int j=0; j<dir.size()-1; j++){
                    int row=r+dir[j];
                    int col=c+dir[j+1];
                    if(row>=0 && col>=0 && row<m && col<n && mat[row][col]==1){
                        freshOranges--;
                        mat[row][col]=2;
                        q.push({row, col});
                    }
                }
            }
        }
        if(freshOranges>0) return -1;
        return time-1;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> mat(n, vector<int>(m, -1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> mat[i][j];
            }
        }
        Solution obj;
        int ans = obj.orangesRotting(mat);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends