class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<pair<int, double>>adj[n+1]; // {node, probability}
        for(int i=0; i<edges.size(); i++)
        {
            adj[edges[i][0]].push_back({edges[i][1], succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }
        vector<double>prob(n, 0);
        prob[start] = 1;
        priority_queue<pair<double, int>>p; // {probability, node}
        p.push({1, start});
        while(!p.empty())
        {
            double pro = p.top().first;
            int curNode = p.top().second;
            p.pop();
            for(auto i: adj[curNode])
            {
                int node = i.first;
                double probab = i.second;
                if(probab * pro > prob[node])
                {
                    prob[node] = probab * pro;
                    p.push({probab * pro, node});
                }
            }
        }
        return prob[end];
    }
};