//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class DisjointSet{
public:
    vector<int>par, usize;
    DisjointSet(int n){
        par.resize(n+1);
        usize.resize(n+1);
        for(int i=1; i<=n; i++) par[i]=i;
    }
    
    int findPar(int node){
        if(par[node]==node) return node;        
        return par[node]=findPar(par[node]);
    }
    
    void unionBySize(int u, int v){
        int paru=findPar(u);
        int parv=findPar(v);
        
        if(usize[paru] < usize[parv]){
            par[paru]=parv;
            usize[parv]++;
        }
        else{
            par[parv]=paru;
            usize[paru]++;
        }
    }
};

class Solution {
  public:
    int Solve(int n, vector<vector<int>>& edge) {
        int extraEdges=0;
        DisjointSet ds(n);
        for(auto it: edge){
            int u=it[0];
            int v=it[1];
            
            if(ds.findPar(u) == ds.findPar(v)) extraEdges++;
            else{
                ds.unionBySize(u, v);
            }
        }
        
        int comp=0;
        for(int i=0; i<n; i++) {
            if(ds.par[i]==i) comp++;
        }
        return extraEdges>=comp-1 ? comp-1 : -1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 2; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution Obj;
        cout << Obj.Solve(n, adj) << "\n";
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends