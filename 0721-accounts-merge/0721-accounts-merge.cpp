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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        DisjointSet d(n);
        unordered_map<string, int>m;
        for(int i=0; i<n; i++)
        {
            for(int j=1; j<accounts[i].size(); j++)
            {
                string mail = accounts[i][j];
                if(!m.count(mail))
                {
                    m[mail] = i;
                }
                else
                {
                    d.unionSize(m[mail], i); 
                }
            }
        }
        vector<vector<string>>ans(n);
        for(auto i: m)
        {
            string mail = i.first;
            int par = d.findPar(i.second);
            ans[par].push_back(mail);
        }
        vector<vector<string>>res;
        for(int i=0; i<n; i++)
        {
            if(!ans[i].empty())
            {
                sort(ans[i].begin(), ans[i].end());
                ans[i].insert(ans[i].begin(), accounts[i][0]);
                res.push_back(ans[i]);
            }
        }
        return res;
    }
};