//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int minIteration(int n, int m, int x, int y){    
        // code here
        vector<vector<int>>vis(n, vector<int>(m));
        queue<pair<int, int>>q;
        x--;
        y--;
        q.push({x, y});
        vis[x][y]=1;
        int ans=0;
        vector<int>row={-1,0,1,0}, col={0,1,0,-1};
        while(!q.empty())
        {
            int sz=q.size();
            bool pos=0;
            for(int i=0; i<sz; i++)
            {
                int a=q.front().first, b=q.front().second;
                q.pop();
                for(int j=0; j<4; j++)
                {
                    int r=row[j]+a, c=col[j]+b;
                    if(r>=0 && r<n && c>=0 && c<m && !vis[r][c])
                    {
                        pos=1;
                        vis[r][c]=1;
                        q.push({r, c});
                    }
                }
            }
            if(pos) ans++;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, M, x, y;
        cin >> N >> M;
        cin >> x >> y;
        
        Solution ob;
        cout << ob.minIteration(N, M, x, y) << endl;
    }
    return 0; 
} 
// } Driver Code Ends