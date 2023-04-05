//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int countSpecialNumbers(int n, vector<int> &arr) {
        sort(arr.begin(), arr.end());
        unordered_map<int, int>m;
        int maxi=INT_MIN;
        for(int i: arr)
        {
            maxi=max(maxi, i);
            m[i]++;
        }
        unordered_map<int, int>ans;
        vector<int>vis(maxi+1);
        for(int i=0; i<n; i++)
        {
            int num=arr[i];
            if(num!=1 && m.count(1))
            {
                ans[num]=1;
            }
            if(m[num]>1)
            {
                ans[num]=1;
            }
            if(!vis[num])
            {
                for(int j=num+num;j<=maxi;j+=num)
                {
                    if(m.count(j))
                    {
                        ans[j]=1;
                    }
                    vis[j]=1;
                }
                vis[num]=1;
            }
        }
        int res=0;
        for(int i=0; i<n; i++)
        {
            if(ans[arr[i]])
            {
                res++;
            }
        }
        return res;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }

        Solution ob;
        cout << ob.countSpecialNumbers(N, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends