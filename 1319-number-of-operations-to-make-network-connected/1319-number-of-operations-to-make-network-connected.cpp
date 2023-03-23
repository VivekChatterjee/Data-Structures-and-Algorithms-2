class Solution {
public:
    vector<int>par, size;
    int findPar(int a)
    {
        if(par[a]==a) return a;
        return par[a]=findPar(par[a]);
    }
    void unionSize(int a, int b)
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
    int makeConnected(int n, vector<vector<int>>& c) {
        if(c.size()<n-1) return -1;
        par.resize(n);
        size.resize(n, 1);
        for(int i=0; i<n; i++)
        {
            par[i]=i;
        }
        for(auto i: c)
        {
            unionSize(i[0], i[1]);
        }
        int ans=0;
        for(int i=0; i<n; i++)
        {
            int parent=findPar(i);
            if(parent==i)
            ans++;
        }
        return ans-1;
    }
};