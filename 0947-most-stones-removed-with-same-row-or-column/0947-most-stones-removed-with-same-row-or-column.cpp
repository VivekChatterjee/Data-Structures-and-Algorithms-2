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
    int removeStones(vector<vector<int>>& stones) {
        int maxRow = 0, maxCol = 0;
        for(auto it: stones)
        {
            maxRow = max(maxRow, it[0]);
            maxCol = max(maxCol, it[1]);
        }
        int n = stones.size();
        DisjointSet d(maxRow + maxCol + 1);
        for(auto it: stones)
        {
            d.unionSize(it[0], maxRow + it[1] + 1);
        }
        int connectedComponents = 0;
        for(int i=0; i<=maxRow + 1 + maxCol; i++)
        {
            if(d.findPar(i) == i && d.size[i] > 1) connectedComponents++;
        }
        return (n - connectedComponents);
    }
};