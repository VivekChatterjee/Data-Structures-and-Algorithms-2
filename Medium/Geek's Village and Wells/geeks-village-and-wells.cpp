//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    vector<vector<int>> chefAndWells(int n, int m, vector<vector<char>> &c){
        vector<vector<int>>ans(n, vector<int>(m, -1));
        vector<vector<int>>vis(n, vector<int>(m));
        queue<pair<int, pair<int, int>>>q;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(c[i][j]=='W')
                {
                    q.push({0, {i, j}});
                    ans[i][j]=0;
                    vis[i][j]=1;
                }
                else if(c[i][j]=='N')
                {
                    vis[i][j]=1;
                    ans[i][j]=0;
                }
                else if(c[i][j]=='.')
                {
                    ans[i][j]=0;
                }
            }
        }
        vector<int>dir={-1, 0, 1, 0, -1};
        while(!q.empty())
        {
                int curDis=q.front().first;
                int row=q.front().second.first;
                int col=q.front().second.second;
                q.pop();
                for(int i=0; i<4; i++)
                {
                    int r=row+dir[i];
                    int co=col+dir[i+1];
                    if(r>=0 && r<n && co>=0 && co<m && !vis[r][co] && (c[r][co]=='.' || c[r][co]=='H'))
                    {
                        vis[r][co]=1;
                        q.push({curDis+1, {r, co}});
                        if(c[r][co]=='H') ans[r][co]=(curDis+1)*2;
                    }
                }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<vector<char>> c(n,vector<char>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>c[i][j];
            }
        }
        Solution ob;
        vector<vector<int>> res=ob.chefAndWells(n,m,c);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout<<res[i][j]<<" ";
            }
            cout<<endl;
        }
    }
}
// } Driver Code Ends