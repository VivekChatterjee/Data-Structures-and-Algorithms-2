//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
    public:
        int coins(int i, int j, vector<int>&a, vector<vector<int>>&dp)
        {
            if(i>j) return 0;
            if(dp[i][j]!=-1) return dp[i][j];
            int ans=0;
            for(int cur=i; cur<=j; cur++)
            {
                int pro=a[i-1]*a[cur]*a[j+1];
                pro+=coins(i, cur-1, a, dp)+coins(cur+1, j, a, dp);
                ans=max(ans, pro);
            }
            return dp[i][j]=ans;
        }
        int maxCoins(int n, vector <int> &a)
        {
            a.push_back(1);
            a.insert(a.begin(), 1);
            vector<vector<int>>dp(n+2, vector<int>(n+2, -1));
            return coins(1, n, a, dp);
        }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution S;
        cout<<S.maxCoins(n,a)<<endl;
    }
    return 0;
}
// } Driver Code Ends