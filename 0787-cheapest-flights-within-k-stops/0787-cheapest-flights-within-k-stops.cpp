#define pii pair<int, pair<int, int>>
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int, int>>adj[n]; // {node, cost}
        for(auto i: flights)
        {
            adj[i[0]].push_back({i[1], i[2]});
        }
        vector<int>dis(n, 1e7);
        dis[src] = 0;
        // priority_queue<pii, vector<pii>, greater<pii>>p;
        queue<pii>p;
        // {stops, {node, cost}}
        p.push({0, {src, 0}});
        while(!p.empty())
        {
            auto cur = p.front();
            p.pop();
            int stops = cur.first;
            int flight = cur.second.first;
            int curCost = cur.second.second;
            for(auto to: adj[flight])
            {
                int toFlight = to.first;
                int cost = to.second;
                int stop = stops;
                if(toFlight != dst) stop+=1;
                if(curCost + cost < dis[toFlight] && stop <= k)
                {
                    dis[toFlight] = curCost + cost;
                    p.push({stop, {toFlight, curCost + cost}});
                }
            }
        }
        return (dis[dst] == 1e7)? -1 : dis[dst];
    }
};