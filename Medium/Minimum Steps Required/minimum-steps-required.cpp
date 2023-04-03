//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

int minSteps(string str) {
    // Write your code here.
    int n=str.size();
    int size=0, j=0;
    while(j<n)
    {
        size++;
        char c=str[j];
        while(j<n && c==str[j])
        {
            j++;
        }
    }
    int ans=n;
    if(size%2!=0)
    {
        ans=1+(size-1)/2;
    }
    else
    {
        ans=2+(size-1)/2;
    }
    return ans;
}

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        cout << minSteps(str) << endl;
    }
}

// } Driver Code Ends