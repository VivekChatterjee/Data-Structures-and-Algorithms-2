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
    string smallestEquivalentString(string s1, string s2, string base) {
        DisjointSet ds(26);
        int n=s1.size();
        for(int i=0; i<n; i++)
        {
            ds.unionRank((s1[i]-'a') , (s2[i]-'a'));
        }
        unordered_map<int, set<int>>m;
        for(int i=0; i<n; i++)
        {
            int a=s1[i]-'a';
            int b=s2[i]-'a';
            int parA=ds.findPar(a);
            int parB=ds.findPar(b);
            m[parA].insert(a);
            m[parA].insert(parA);
            m[parB].insert(b);
            m[parB].insert(parB);
        }
        string s="";
        for(int i=0; i<base.size(); i++)
        {
            int a=base[i]-'a';
            int parA=ds.findPar(a);
            if(!m.count(parA)) s+=base[i];
            else
            s+=(char)(*(m[parA]).begin() + 'a');
        }
        return s;
    }
};