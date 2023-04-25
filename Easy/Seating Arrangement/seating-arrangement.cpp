//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    bool is_possible_to_get_seats(int n, int m, vector<int>& s){
        if(m==1)
        {
            if(n>=1 && s[0]==1) return 0;
            return 1;
        }
        int ct=0;
        if(s[0]==0 && s[1]==0)
        {
            ct++;
            s[0]=1;
        }
        if(s[m-1]==0 && s[m-2]==0)
        {
            ct++;
            s[m-1]=1;
        }
        int z=0;
        for(int i=0; i<m; i++)
        {
            if(s[i]==1)
            {
                z=0;
            }
            else if(s[i]==0)
            {
                z++;
                if(z==3)
                {
                    ct++;
                    z-=2;
                }
            }
        }
        return ct>=n;
    }
};

//{ Driver Code Starts.

int main(){

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int m;
        cin >> m;
        vector<int> seats(m);
        for (int i = 0; i < m; i++) {
            cin >> seats[i];
        }
        Solution obj;
        if (obj.is_possible_to_get_seats(n, m, seats)) {
            cout << "Yes" << endl;
        }
        else {
            cout << "No" << endl;
        }
    }
}

// } Driver Code Ends