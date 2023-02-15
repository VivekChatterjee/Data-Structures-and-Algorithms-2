//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class Solution{
public:
    int good(int i, vector<int>&arr, vector<int>&vis)
    {
        int n=arr.size();
        if(i<0 || i>=n) return 2; // safe
        if(arr[i]==0) return 1; // self loop
        if(vis[i]) return vis[i];
        if(vis[i]!=0) return vis[i];
        vis[i]=1;
        int go=good(i+arr[i], arr, vis);
        return vis[i]=go;
    }
    int goodStones(int n,vector<int> &arr){
        vector<int>vis(n);
        for(int i=0; i<n; i++)
        {
            if(!vis[i])
            good(i, arr, vis);
        }
        int ans=0;
        for(int i: vis)
        {
            if(i==2) ans++;
        }
        return ans;
    }  
};

//{ Driver Code Starts.

int main(){
    
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        cout<<ob.goodStones(n,arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends