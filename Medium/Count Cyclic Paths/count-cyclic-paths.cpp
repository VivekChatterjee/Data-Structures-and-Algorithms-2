//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++
class Solution{   
public:
    // long long K=1e9+7;
    // long long count(int i, int n, vector<vector<long long>> &dp)
    // {
    //     if(n<0) return 0;
    //     if(n==0)
    //     {
    //         return i==0;
    //     }
    //     long long  ans=0;
    //     if(dp[i][n] != -1) return dp[i][n];
    //     if(i==0)
    //     {
    //         ans+=count(1, n-1, dp)%K;
    //         ans+=count(2, n-1, dp)%K;
    //         ans+=count(3, n-1, dp)%K;
    //     }
    //     else if(i==1)
    //     {
    //         ans+=count(0, n-1, dp)%K;
    //         ans+=count(2, n-1, dp)%K;
    //         ans+=count(3, n-1, dp)%K;
    //     }
    //     else if(i==2)
    //     {
    //         ans+=count(0, n-1, dp)%K;
    //         ans+=count(1, n-1, dp)%K;
    //         ans+=count(3, n-1, dp)%K;
    //     }
    //     else
    //     {
    //         ans+=count(0, n-1, dp)%K;
    //         ans+=count(1, n-1, dp)%K;
    //         ans+=count(2, n-1, dp)%K;
    //     }
    //     return dp[i][n]=ans%K;
    // }
    // int countPaths(int n)
    // {
    //     vector<vector<long long>> dp(4, vector<long long>(n+2, -1));
    //     long long ans = count(0, n, dp);
    //     return ans%K;
    // }
    int countPaths(int N){
        // code here
        if(N<=1)
            return 0;
        int mod=1e9+7;
        vector<vector<int>> dp(N+1, vector<int>(2,0));
        dp[2][0]=2;dp[2][1]=3;
        
        if(N==2)
            return dp[N][1];
        
        for(int n=3;n<=N;n++)
        {
            int temp1 = dp[n-1][0]%mod;  
            int temp2 = dp[n-1][1]%mod;
            dp[n][0] = (((2*temp1)%mod)+temp2)%mod;  
            dp[n][1] = (((2*temp1)%mod)+temp1)%mod;
        }
        return dp[N][1];
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        
        Solution ob;
        cout << ob.countPaths(N) << endl;
    }
    return 0; 
}

// } Driver Code Ends