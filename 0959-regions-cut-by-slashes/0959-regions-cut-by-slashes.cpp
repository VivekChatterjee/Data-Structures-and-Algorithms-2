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
    void unionRank(int node1, int node2, int &ans)
    {
        int par1 = findPar(node1);
        int par2 = findPar(node2);
        if (par1 == par2)
        {
            ans++;
        }
        else
        {
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
    int ans = 1;
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        int dots = n+1;
        DisjointSet d(dots * dots);
        for(int i=0; i<dots; i++)
        {
            for(int j=0; j<dots; j++)
            {
                if(i==0 || i==dots-1 || j==0|| j==dots-1)
                {
                    int cell = i*dots + j;
                    if(cell != 0)
                    d.unionRank(0, cell, ans);
                }
            }
        }
        
        for(int i=0; i<grid.size(); i++)
        {
            string s = grid[i];
            for(int j=0; j<s.size(); j++)
            {
                if(s[j] == '/')
                {
                    int cell1 = i*dots + j+1;
                    int cell2 = (i+1)*dots + j;
                    d.unionRank(cell1, cell2, ans);
                }
                else if(s[j] == '\\')
                {
                    int cell1 = i*dots + j;
                    int cell2 = (i+1)*dots + j+1;
                    d.unionRank(cell1, cell2, ans);
                }
            }
        }
        return ans;
    }
};