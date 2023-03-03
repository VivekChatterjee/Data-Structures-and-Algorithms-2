class Solution {
public:
    vector<int>par, sz;
    int findPar(int node)
    {
        if(par[node]==node) return node;
        return par[node]=findPar(par[node]);
    }
    void unionSize(int a, int b)
    {
        int parA=findPar(a);
        int parB=findPar(b);
        if(parA==parB) return;
        if(sz[parA]>=sz[parB])
        {
            par[parB]=parA;
            sz[parA]+=sz[parB];
        }
        else
        {
            par[parA]=parB;
            sz[parB]+=sz[parA];
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size(), maxr=0, maxc=0;
        for(int i=0; i<n; i++)
        {
            maxr=max(maxr, stones[i][0]);
            maxc=max(maxc, stones[i][1]);
        }
        par.resize(maxr+maxc+2);
        sz.resize(maxr+maxc+2, 1);
        for(int i=0; i<par.size(); i++)
        {
            par[i]=i;
        }
        for(auto it: stones)
        {
            unionSize(it[0], it[1]+maxr+1);
        }
        int ct=0;
        for(int i=0; i<maxr+maxc+2; i++)
        {
            int parent=findPar(i);
            if(parent==i && sz[parent]>1) ct++;
        }
        return n-ct;
    }
};