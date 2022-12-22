// PRIM'S ALGO
#define pii pair<int, pair<int, int>>
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<int>vis(n);
        priority_queue<pii, vector<pii>, greater<pii>>p; 
        // {weight, {node, parent}}
        p.push({0, {0, -1}});
        int cost = 0;
        while(!p.empty())
        {
            int curWt = p.top().first;
            int curNode = p.top().second.first;
            int curPar = p.top().second.second;
            p.pop();
            if(!vis[curNode])
            {
                vis[curNode] = 1;
                cost+=curWt;
                for(int i=0; i<n; i++)
                {
                    if(i != curNode && !vis[i])
                    {
                        int wt = abs(points[curNode][0] - points[i][0]) + abs(points[curNode][1] - points[i][1]);
                        p.push( {wt, {i, curNode}});
                    }
                }
            }
        }
        return cost;
    }
};