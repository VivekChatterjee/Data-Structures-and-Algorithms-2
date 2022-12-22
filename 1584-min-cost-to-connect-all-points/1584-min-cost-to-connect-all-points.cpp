// KRUSKAL'S ALGO
#define pii pair<int, pair<int, int>>
class DisjointSet
{
    vector<int>rank, size, parent;
    public:
    DisjointSet(int n)
    {
        rank.resize(n+1, 0);
        size.resize(n+1, 1);
        parent.resize(n+1);
        for(int i=0; i<=n; i++) parent[i] = i;
    }
    int findPar(int node)
    {
        if(parent[node] == node) return node;
        return parent[node] = findPar(parent[node]);
    }
    void findUnionByRank(int node1, int node2)
    {
        int par1 = findPar(node1);
        int par2 = findPar(node2);
        if(par1 == par2) return;
        if(rank[par2] > rank[par1]) parent[par1] = par2;
        else if(rank[par1] > rank[par2]) parent[par2] = par1;
        else
        {
            parent[par2] = par1;
            rank[par1]+=1;
        }
    }
    void findUnionBySize(int node1, int node2)
    {
        int par1 = findPar(node1);
        int par2 = findPar(node2);
        if(par1 == par2) return;
        if(size[par1] > size[par2])
        {
            parent[par1] = par2;
            size[par2]+=size[par1];
        }
        else
        {
            parent[par2] = par1;
            size[par1]+=size[par2];
        }
    }
};
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<pii> edges;
        int n = points.size();
        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                int pt1x = points[i][0];
                int pt1y = points[i][1];
                int pt2x = points[j][0];
                int pt2y = points[j][1];
                int manDist = abs(pt1x - pt2x) + abs(pt1y - pt2y);
                edges.push_back({manDist, {i, j}});
            }
        }
        sort(edges.begin(), edges.end());
        int cost=0;
        DisjointSet d(n);
        for(auto it: edges)
        {
            int wt = it.first;
            int nd1 = it.second.first;
            int nd2 = it.second.second;
            if(d.findPar(nd1) != d.findPar(nd2))
            {
                cost+=wt;
                d.findUnionByRank(nd1, nd2);
            }
        }
        return cost;
    }
};