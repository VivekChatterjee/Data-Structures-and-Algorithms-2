//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int unvisitedLeaves(int n, int l, int frogs[]) {
        vector<int>vis(l+1);
        for(int i=0; i<n; i++)
        {
            int start=frogs[i];
            if(start<=l && !vis[start])
            {
                for(int j=start; j<=l; j+=start)
                {
                    vis[j]=1;
                }
            }
        }
        int ans=0;
        for(int i=1; i<=l; i++)
        {
            if(!vis[i]) ans++;
        }
        return ans;
    }
};


//{ Driver Code Starts.


int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, leaves;
        cin >> N >> leaves;
        int frogs[N];
        for (int i = 0; i < N; i++) {
            cin >> frogs[i];
        }

        Solution ob;
        cout << ob.unvisitedLeaves(N, leaves, frogs) << endl;
    }
}
// } Driver Code Ends