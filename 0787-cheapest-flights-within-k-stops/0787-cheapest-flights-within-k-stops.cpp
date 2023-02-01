#define pii pair<int, pair<int, int>>
#define pi pair<int, int>
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pi>adj[n]; // {node, weight}
        for(auto i: flights)
        {
            adj[i[0]].push_back({i[1], i[2]});
        }
        vector<int>dis(n, 1e8);
        priority_queue<pii, vector<pii>, greater<pii>>p;
        p.push({0, {0, src}});
        // {stops, {price, node}}
        while(!p.empty())
        {
            int stop=p.top().first;
            int pastPrice=p.top().second.first;
            int node=p.top().second.second;
            p.pop();
            if(stop > k) break;
            for(auto it: adj[node])
            {
                int curPrice=it.second+pastPrice;
                int curNode=it.first;
                int curStop=(curNode == dst)? stop : stop+1;
                if(curPrice<dis[curNode] && curStop<=k)
                {
                    dis[curNode]=curPrice;
                    p.push({curStop, {curPrice, curNode}});
                }
            }
        }
        return (dis[dst] == 1e8)? -1 : dis[dst];
    }
};