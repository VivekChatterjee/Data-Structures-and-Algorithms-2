//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution {
  public:
    string removeReverse(string s) {
        int n=s.size();
        bool front=1;
        map<char, vector<int>>m;
        int i=0, j=n-1;
        vector<int>block(n, 1);
        for(int i=0; i<n; i++)
        {
            m[s[i]].push_back(i);
        }
        while(i<=j)
        {
            if(front)
            {
                if(m[s[i]].size() > 1)
                {
                    int ind=m[s[i]].front();
                    m[s[i]].erase(m[s[i]].begin());
                    block[ind]=0;
                    front=!front;
                }
                i++;
            }
            else
            {
                if(m[s[j]].size() > 1)
                {
                    int ind=m[s[j]].back();
                    m[s[j]].pop_back();
                    block[ind]=0;
                    front=!front;
                }
                j--;
            }
        }
        string ans="";
        if(front)
        {
            for(int i=0; i<n; i++)
            {
                if(block[i]) ans+=s[i];
            }
        }
        else
        {
            for(int i=n-1; i>=0; i--)
            {
                if(block[i]) ans+=s[i];
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
        string S;
        cin>>S;
        Solution obj;
        auto ans = obj.removeReverse(S);
        cout<<ans<<endl;
    }
}
// } Driver Code Ends