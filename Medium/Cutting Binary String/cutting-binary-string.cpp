//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
private:
    long solve(int i, string &s) {
        
        if(s[i] == '0') {
            return INT_MAX;
        }
        if(i == s.size()) {
            return 0;
        }
        
        int num = 0;
        long mini = INT_MAX;
        
        for(int j = i; j < s.size(); j++) {
            num = num * 2 + (s[j] - '0');
            
            for(int p = 0; p < 15; p++) {
                if(num == pow(5, p)) {
                    long cut = 1 + solve(j+1, s);
                    mini = min(mini, cut);
                }
            }
        }
        return mini;
    }
    
public:
    int cuts(string s){
    
        int ans = solve(0, s);
        
        return ans == INT_MAX ? -1 : ans;
    }
};


//{ Driver Code Starts.
int main()
{
   int t;
   cin>>t;
   string s;
   while(t--)
   {
    cin>>s;
    Solution obj;
    int res=obj.cuts(s);
    cout<<res<<endl;

   }


    return 0;
}

// } Driver Code Ends