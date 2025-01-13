//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class DisjointSet{
    vector<int>par, rank;
public:
    DisjointSet(int n){
        par.resize(n+1);
        rank.resize(n+1);
        for(int i=1; i<=n; i++) par[i]=i;
    }
    
    int findPar(int node){
        if(par[node]==node) return node;        
        return par[node]=findPar(par[node]);
    }
    
    void unionByRank(int u, int v){
        int paru=findPar(u);
        int parv=findPar(v);
        
        if(rank[paru] < rank[parv]){
            par[paru]=parv;
        }
        else if(rank[paru] > rank[parv]){
            par[parv]=paru;
        }
        else{
            par[paru]=parv;
            rank[parv]++;
        }
    }
};

class Solution {
  public:
    int numProvinces(vector<vector<int>> adj, int v) {
        DisjointSet ds(v);
        for(int i=0; i<adj.size(); i++){
            for(int j=0; j<adj[i].size(); j++){
                if(adj[i][j] && i!=j){
                    ds.unionByRank(i, j);
                }
            }
        }
        set<int>s;
        for(int i=0; i<v; i++){
            s.insert(ds.findPar(i));
        }
        return s.size();
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends