//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumSum(string s) {
    // a ? ? ? c ? | ? c ? ? ? a
    int n = s.length(), ans = 0;
    for(int i = 0, j = n-1; i < j; i++, j--) {
        if(s[i] != '?' && s[j] != '?') {
            if(s[i] != s[j]) return -1;
            continue;
        }
        if(s[i] == '?' && s[j] == '?') continue;
        if(s[i] == '?') s[i] = s[j];
        else s[j] = s[i];
    }
    char last = '?';
    for(int i = 0, j = n-1; i < n; i++, j--) {
        if(s[i] == '?') {
            if(last != '?') {
                s[i] = s[j] = last;
            }
        } else {
            if(last != '?') ans += abs(s[i] - last);
            last = s[i];
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
        string s;
        cin >> s;

        Solution ob;
        int ans = ob.minimumSum(s);
        cout << ans;
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends