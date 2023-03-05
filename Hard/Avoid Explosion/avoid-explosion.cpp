//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<int>par, size;
    int findPar(int a)
    {
        if(par[a]==a) return a;
        return par[a]=findPar(par[a]);
    }
    void uni(int a, int b)
    {
        int parA=findPar(a);
        int parB=findPar(b);
        if(parA==parB) return;
        else if(size[parA]>=size[parB])
        {
            par[parB]=parA;
            size[parA]+=size[parB];
        }
        else
        {
            par[parA]=parB;
            size[parB]+=size[parA];
        }
    }
    vector<string> avoidExplosion(vector<vector<int>> mix, int n,
    vector<vector<int>> danger, int m) 
    {
        par.resize(n+1);
        size.resize(n+1, 1);
        for(int i=0; i<=n; i++)
        {
            par[i]=i;
        }
        vector<string>ans;
        for(auto &i: mix)
        {
            int parA=findPar(i[0]);
            int parB=findPar(i[1]);
            bool pos=1;
            for(auto &it: danger)
            {
                int parC=findPar(it[0]);
                int parD=findPar(it[1]);
                if((parA==parC && parB==parD) || (parA==parD && parB==parC))
                {
                    pos=0;
                    break;
                }
            }
            if(pos)
            {
                ans.push_back("Yes");
                uni(i[0], i[1]);
            }
            else
            {
                ans.push_back("No");
            }
        }
        return ans;
    }
};






//{ Driver Code Starts.

int main() {
    int tt;
    cin >> tt;
    Solution sol;
    while (tt--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> mix(n, vector<int>(2));
        vector<vector<int>> danger(m, vector<int>(2));
        for (int i = 0; i < n; i++) {
            cin >> mix[i][0] >> mix[i][1];
        }

        for (int i = 0; i < m; i++) {
            cin >> danger[i][0] >> danger[i][1];
        }

        auto ans = sol.avoidExplosion(mix, n, danger, m);
        for (auto &val : ans) cout << val << " ";
        cout << "\n";
    }

    return 0;
}

// } Driver Code Ends