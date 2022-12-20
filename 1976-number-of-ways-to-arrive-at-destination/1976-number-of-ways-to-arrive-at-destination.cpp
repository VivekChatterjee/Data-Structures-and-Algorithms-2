#define ll long long int
#define pii pair<ll, ll>
class Solution {
public:
    ll K = 1e9+7;
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pii>adj[n];
        for(auto i: roads)
        {
            adj[i[0]].push_back({(ll)i[1], (ll)i[2]}); // {node, time}
            adj[i[1]].push_back({(ll)i[0], (ll)i[2]});
        }
        priority_queue<pii, vector<pii>, greater<pii>>p;
        p.push({0, 0});
        // {time, node}
        vector<ll>dis(n, LONG_MAX);
        vector<ll>ways(n,0);
        dis[0] = 0;
        ways[0] = 1;
        while(!p.empty())
        {
            auto cur = p.top();
            p.pop();
            ll time = cur.first;
            ll node = cur.second;
            for(auto nbr: adj[node])
            {
                ll newNode = nbr.first;
                ll newTime = nbr.second;
                if(time + newTime < dis[newNode])
                {
                    dis[newNode] = (ll)time + (ll)newTime;
                    p.push({time + newTime, newNode});
                    ways[newNode] = (ll)ways[node];
                }
                else if(time + newTime == dis[newNode])
                {
                    ways[newNode] = (ways[newNode] + ways[node]) % K;
                }
            }
        }
        return ways[n-1] % K;
    }
};