#define pii pair<int, int>
// DIJKSTRA'S ALGO
class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<pii>adj[n];
        for(auto i: edges)
        {
            adj[i[0]].push_back({i[1], i[2]}); // {node, distance}
            adj[i[1]].push_back({i[0], i[2]});
        }
        priority_queue<pii, vector<pii>, greater<pii>>p; // {distance, node}
        int cityCount = 1e8, cityNumber = -1;
        for(int i=0; i<n; i++)
        {
            vector<int>dis(n, 1e8);
            dis[i] = 0;
            p.push({0, i});
            while(!p.empty())
            {
                auto cur = p.top();
                p.pop();
                int curD = cur.first;
                int curNode = cur.second;
                for(auto i: adj[curNode])
                {
                    int node = i.first;
                    int distance = i.second;
                    if(curD + distance < dis[node])
                    {
                        dis[node] = curD + distance;
                        p.push({curD + distance, node});
                    }
                }
            }
            int ct = 0;
            for(int i=0; i<n; i++)
            {
                if(dis[i] <= distanceThreshold) ct++;
            }
            if(ct <= cityCount)
            {
                cityCount = ct;
                cityNumber = i;
            }
        }
        
        return cityNumber;        
    }
};