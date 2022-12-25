class Solution {
public:
    void dfs(string a, string b, double &res, bool &found, map<string, int>&vis,  map<string, map<string, double>>&val, map<string, vector<string>> &adj)
    {
        vis[a] = 1;
        for(auto child: adj[a])
        {
            if(vis[child] != 1)
            {
                res *= val[a][child];
                if(child == b)
                {
                    found = true;
                    return;
                }
                dfs(child, b, res, found, vis, val, adj);
                if(found) return;
                else res /= val[a][child];
            }
        }
    }
    vector<double> calcEquation(vector<vector<string>>& eq, vector<double>& values, vector<vector<string>>& q) {
        map<string, map<string, double>>val;
        map<string, vector<string>>adj;
        for(int i=0; i<eq.size(); i++)
        {
            string a = eq[i][0];
            string b = eq[i][1];
            val[a][b] = values[i];
            val[b][a] = (1/values[i]);
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        vector<double>ans;
        for(int i=0; i<q.size(); i++)
        {
            string a = q[i][0], b = q[i][1];
            double res = 1;
            if(!adj.count(a) || !adj.count(b)) ans.push_back(-1);
            else if(a == b) ans.push_back(1);
            else
            {
                res = 1;
                bool found = false;
                map<string, int>vis;
                dfs(a, b, res, found, vis, val, adj);
                if(found) ans.push_back(res);
                else ans.push_back(-1);
            }
        }
        return ans;
    }
};