//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

// class Solution {
//   public:
//     vector<int>par;
//     int findPar(int a)
//     {
//         if(par[a]==a) return a;
//         return par[a]=findPar(par[a]);
//     }
//     vector<string> avoidExplosion(vector<vector<int>> mix, int n,
//     vector<vector<int>> danger, int m) 
//     {
//         par.resize(n+1);
//         for(int i=0; i<=n; i++)
//         {
//             par[i]=i;
//         }
//         vector<int>prev=par;
//         vector<string>ans;
//         for(auto i: mix)
//         {
//             int parA=findPar(i[0]);
//             int parB=findPar(i[1]);
//             if(parA!=parB)
//             {
//                 par[parA]=parB;
//             }
//             bool pos=1;
//             for(auto it: danger)
//             {
//                 int parA=findPar(it[0]);
//                 int parB=findPar(it[1]);
//                 if(parA==parB)
//                 {
//                     pos=0;
//                 }
//             }
//             if(pos)
//             {
//                 ans.push_back("Yes");
//                 prev=par;
//             }
//             else
//             {
//                 ans.push_back("No");
//                 par=prev;
//             }
//         }
//         return ans;
//     }
// };

class Solution {
  public:
    int dsu(vector<int>& parent, int x){
        if(parent[x] == x){
            return x;
        }
        return parent[x] = dsu(parent,parent[x]);
    }
    vector<string> avoidExplosion(vector<vector<int>> mix, int n, vector<vector<int>> danger, int m){
    
        vector<int>parent(n+1),org(n+1);
        vector<string>ans(n);
        for(int i = 0; i <= n; i++){
            parent[i] = i;
        }
        org = parent;
        for(int i = 0; i < n; i++){
            int paru = dsu(parent,mix[i][0]), parv = dsu(parent,mix[i][1]);
            if(paru != parv){
                parent[paru] = parv;
            }
            bool c = true;
            for(int j = 0; j < m; j++){
                int parx = dsu(parent,danger[j][0]),pary = dsu(parent,danger[j][1]);
                if(parx == pary){
                    c = false;
                }
            }
            if(c){
                ans[i] = "Yes";
                org = parent;
            }
            else{
                ans[i] = "No";
                parent = org;
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