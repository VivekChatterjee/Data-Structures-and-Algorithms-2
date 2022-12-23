class DisjointSet
{
public:
    vector<int> rank, size, parent;
    DisjointSet(int n)
    {
        rank.resize(n + 1, 0);
        size.resize(n + 1, 1);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++)
            parent[i] = i;
    }
    int findPar(int node)
    {
        if (parent[node] == node)
            return node;
        return parent[node] = findPar(parent[node]);
    }
    void unionRank(int node1, int node2)
    {
        int par1 = findPar(node1);
        int par2 = findPar(node2);
        if (par1 == par2)
            return;
        if (rank[par2] > rank[par1])
            parent[par1] = par2;
        else if (rank[par1] > rank[par2])
            parent[par2] = par1;
        else
        {
            parent[par2] = par1;
            rank[par1] += 1;
        }
    }
    void unionSize(int node1, int node2)
    {
        int par1 = findPar(node1);
        int par2 = findPar(node2);
        if (par1 == par2)
            return;
        if (size[par1] > size[par2])
        {
            parent[par1] = par2;
            size[par2] += size[par1];
        }
        else
        {
            parent[par2] = par1;
            size[par1] += size[par2];
        }
    }
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        DisjointSet d(n);
        vector<pair<int, int>>ans;
        for(int i=0; i<n; i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            if(d.findPar(u) != d.findPar(v)) d.unionRank(u, v);
            else return {u, v};
        }
        return {};
    }
};