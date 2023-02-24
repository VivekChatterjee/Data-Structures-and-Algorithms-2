//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int check(int i, int j, string &s, string &t)
    {
        int n=s.size(), nn=t.size();
        if(i==n && j==nn) return 1;
        if(i>=n || j>=nn) return 0;
        if(t[j]>='0' && t[j]<='9')
        {
            string st="";
            int p=j;
            
            while(p<nn && t[p]>='0' && t[p]<='9')
            {
                st+=t[p];
                p++;
            }
            int go=stoi(st);
            return check(i+go, p, s, t);
        }
        else
        {
            return (s[i]==t[j] && check(i+1, j+1, s, t));
        }
    }
    int checkCompressed(string s, string t) {
        return check(0, 0, s, t);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S,T;
        
        cin>>S>>T;

        Solution ob;
        cout << ob.checkCompressed(S,T) << endl;
    }
    return 0;
}
// } Driver Code Ends