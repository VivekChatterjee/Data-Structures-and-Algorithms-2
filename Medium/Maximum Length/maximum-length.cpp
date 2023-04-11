//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    int solve(int a, int b, int c) {
        if(a>=b && a>=c)
        {
            int req=a/2;
            if(req>=(b+c))
            {
                req-=(b+c);
                req*=2;
                req+=a%2;
                if(req>=3) return -1;
            }
        }
        else if(b>=a && b>=c)
        {
            int req=b/2;
            if(req>=(a+c))
            {
                req-=(a+c);
                req*=2;
                req+=b%2;
                if(req>=3) return -1;
            }
            
        }
        else
        {
            int req=c/2;
            if(req>=(b+a))
            {
                req-=(b+a);
                req*=2;
                req+=c%2;
                if(req>=3) return -1;
            }
            
        }
        return a+b+c;
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int a, b, c;
        cin >> a >> b >> c;

        Solution ob;
        int ans = ob.solve(a, b, c);
     

        cout <<  ans << "\n";
    }
    return 0;
}
// } Driver Code Ends