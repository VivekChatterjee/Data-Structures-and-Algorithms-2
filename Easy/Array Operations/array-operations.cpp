//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int arrayOperations(int n, vector<int> &arr) {
        bool pos=0;
        int ans=0, j=0;
        while(j<n)
        {
            while(j<n && arr[j]==0)
            {
                j++;
                pos=1;
            }
            if(j<n && arr[j]!=0)
            {
                ans++;
                while(j<n && arr[j]!=0)
                {
                    j++;
                }
            }
        }
        if(!pos) return 1;
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
        
        Solution obj;
        int res = obj.arrayOperations(n, arr);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends