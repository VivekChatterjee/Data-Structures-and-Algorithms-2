//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

#define ll long long
class Solution{
public:
    vector<long long> smallerSum(int n, vector<int> &arr){
        unordered_map<int, int>m;
        for(int i=0; i<n; i++)
        {
            m[i]=arr[i];
        }
        sort(arr.begin(), arr.end());
        vector<ll>sum(n);
        sum[0]=1LL*arr[0];
        for(int i=1; i<n; i++) 
        {
            sum[i]=sum[i-1]+ 1LL*arr[i];
        }
        sort(arr.begin(), arr.end(), greater<int>());
        vector<ll>ans;
        for(int i=0; i<n; i++)
        {
            int ind=upper_bound(arr.begin(), arr.end(), m[i], greater<int>())-arr.begin();
            if(n-ind-1>=0)
            ans.push_back(sum[n-ind-1]);
            else
            ans.push_back(0);
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
        vector<long long> ans=ob.smallerSum(n,arr);
        for(int i=0;i<n;i++){
            if(i!=n-1){
                cout<<ans[i]<<" ";
            }
            else{
                cout<<ans[i]<<endl;
            }
        }
    }
    return 0;
}
// } Driver Code Ends