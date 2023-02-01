class Solution {
public:
    vector<int>par, size;
    int findPar(int a)
    {
        if(par[a] == a) return a;
        return par[a] = findPar(par[a]);
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        par.resize(n+1), size.resize(n+1);
        for(int i=0; i<=n; i++)
            par[i]=i;
        for(auto it: edges)
        {
            int parA=findPar(it[0]);
            int parB=findPar(it[1]);
            if(parA == parB) return {it[0], it[1]};
            par[parA]=parB;
        }
        return {-1, -1};
    }
};