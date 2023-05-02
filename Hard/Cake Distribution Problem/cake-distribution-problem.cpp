//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
    public:
    int isValid(int mid, vector<int>&s, int k){
        int pieces=0;
        int cur=0;
        for(int i: s)
        {
            cur+=i;
            if(cur>=mid)
            {
                pieces++;
                cur=0;
            }
        }
        return pieces>=k+1;
    }
    int maxSweetness(vector<int>& s, int n, int k) {
        int start=INT_MAX, end=0;
        for(int i: s)
        {
            start=min(start, i);
            end+=i;
        }
        int ans=-1;
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            if(isValid(mid, s, k))
            {
                ans=mid;
                start=mid+1;
            }
            else
            {
                end=mid-1;
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> sweetness(n);
        for (int i = 0; i < n; i++) {
            cin >> sweetness[i];
        }
          Solution ob;
          int res=ob.maxSweetness(sweetness, n, k);
        cout << res << endl;
    }
}
// } Driver Code Ends