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
    int makeConnected(int n, vector<vector<int>>& connections) {
        int total = connections.size();
        if(total < n-1) return -1;
        int count = 0;
        DisjointSet d(total);
        int one = 0;
        for(int i=0; i<total; i++)
        {
            int a = connections[i][0];
            int b = connections[i][1];
            if(d.findPar(a) != d.findPar(b))
            {
                one = a;
                d.findUnionByRank(a, b);
            }
        }
        for(int i=0; i<n; i++)
        {
            if(d.findPar(i) != d.findPar(one))
            {
                count++;
                d.findUnionByRank(one, i);
            }
        }
        return count;
    }
};