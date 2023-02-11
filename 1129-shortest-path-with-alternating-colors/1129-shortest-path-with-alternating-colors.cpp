#define pii pair<int, pair<int, int>>
#define pi pair<int, int>
class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red, vector<vector<int>>& blue) 
    {
        vector<pi>adj[n];
        for(auto i: red)
        {
            int a=i[0], b=i[1];
            adj[a].push_back({b, 1});
        }
        for(auto i: blue)
        {
            int a=i[0], bb=i[1];
            adj[a].push_back({bb, 0});
        }
        vector<int>dis(n, 1e8);
        queue<pii>p;
        p.push({0, {-1, 0}}); // {distance, {parentColor(0 or 1, -1 for 0th node), node}}
        dis[0]=0;
        while(!p.empty())
        {
            int curDis=p.front().first;
            int parColor=p.front().second.first;
            int parNode=p.front().second.second;
            p.pop();
            for(auto &it: adj[parNode])
            {
                int curNode=it.first;
                int curColor=it.second;
                if(curColor != parColor and curNode != -1)
                {
                    p.push({curDis+1, {curColor, curNode}});
                    if(curDis+1<dis[curNode])
                    {
                        dis[curNode]=curDis+1;
                    }
                    it.first=-1;
                }
            }
        }
        for(auto &it: dis) if(it==1e8) it=-1;
        return dis;
    }
};