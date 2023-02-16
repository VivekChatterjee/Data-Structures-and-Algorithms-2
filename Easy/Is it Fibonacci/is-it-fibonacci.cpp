//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

#define ll long long
class Solution {
  public:
    long long solve(int n, int k, vector<long long> geek) 
    {
        ll ans=-1, i=0, j=0, sum=0;
        while(j<n)
        {
            if(j<=k-1)
            {
                sum+=geek[j];
            }
            else
            {
                geek.push_back(sum);
                sum+=sum-geek[i];
                i++;
            }
            if(j==n-1) ans=geek[j];
            j++;
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, K;
        cin >> N >> K;

        vector<long long> GeekNum(K);

        for (int i = 0; i < K; i++) cin >> GeekNum[i];

        Solution ob;
        cout << ob.solve(N, K, GeekNum) << "\n";
    }
    return 0;
}

// } Driver Code Ends