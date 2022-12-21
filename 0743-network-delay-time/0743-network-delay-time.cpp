#define pii pair<int, int>
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pii>adj[n+1];
        for(auto i: times)
        {
            adj[i[0]].push_back({i[1], i[2]}); // {node, time}
        }
        priority_queue<pii, vector<pii>, greater<pii>>p; // {time, node}
        p.push({0, k});
        vector<int>dis(n+1, 1e8);
        dis[k] = 0;
        while(!p.empty())
        {
            auto cur = p.top();
            p.pop();
            int curTime = cur.first;
            int curNode = cur.second;
            for(auto i: adj[curNode])
            {
                int node = i.first;
                int time = i.second;
                if(time + curTime < dis[node])
                {
                    dis[node] = time + curTime;
                    p.push({time + curTime, node});
                }
            }
        }
        int ans = -1e8;
        for(int i=1; i<=n; i++)
        {
            ans = max(ans, dis[i]);
        }
        return (ans == 1e8)? -1 : ans;
    }
};