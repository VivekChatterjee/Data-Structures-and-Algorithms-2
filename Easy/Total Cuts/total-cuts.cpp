//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int totalCuts(int n,int k,vector<int> &a){
        if(n==1) return 0;
        vector<int>right(n);
        right[n-1]=a[n-1];
        for(int i=n-2; i>=0; i--)
        {
            right[i]=min(right[i+1], a[i+1]);
        }
        int ans=0, left=INT_MIN;
        for(int i=0; i<n-1; i++)
        {
            left=max(left, a[i]);
            if(left+right[i]>=k) ans++;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N,K;
        cin>>N>>K;
        vector<int> A(N);
        for(int i=0;i<N;i++){
            cin>>A[i];
        }
        Solution ob;
        cout<<ob.totalCuts(N,K,A)<<endl;
    }
    return 0;
}
// } Driver Code Ends