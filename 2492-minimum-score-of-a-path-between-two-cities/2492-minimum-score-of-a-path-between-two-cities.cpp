class Solution {
public:
    vector<int>par, size, dis;
    int findPar(int a)
    {
        if(par[a]==a) return a;
        return par[a]=findPar(par[a]);
    }
    void unionSize(int a, int b, int path)
    {
        int parA=findPar(a);
        int parB=findPar(b);
        if(parA==parB)
        {
        dis[parA]=min(dis[parA], path);
        dis[parB]=min(dis[parB], path);
         return;
        }
        else if(size[parA]>size[parB])
        {
            dis[parA]=min(dis[parA], path);
            par[parB]=parA;
            size[parA]+=size[parB];
        }
        else
        {
            dis[parB]=min(dis[parB], path);
            par[parA]=parB;
            size[parB]+=size[parA];
        }
    }
    int minScore(int n, vector<vector<int>>& roads) {
        par.resize(n+1);
        size.resize(n+1, 1);
        dis.resize(n+1, 1e6);
        for(int i=1; i<=n; i++)
        {
            par[i]=i;
        }
        for(auto i: roads)
        {
            unionSize(i[0], i[1], i[2]);
        }
        for(auto i: roads)
        {
            unionSize(i[0], i[1], i[2]);
        }
        return dis[findPar(1)];
    }
};