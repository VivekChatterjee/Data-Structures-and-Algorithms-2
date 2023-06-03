// bfs se banega
class Solution {
public:
    int numOfMinutes(int n, int headId, vector<int>& manager, vector<int>&info) 
    {
        vector<int>adj[n];
        for(int i=0; i<n; i++)
        {
            if(manager[i] != -1)
            adj[manager[i]].push_back(i);
        }
        queue<pair<int, int>>q;
        q.push({headId, 0});
        int ans = 0;
        while(!q.empty())
        {
            int size = q.size();
            while(size--)
            { 
                int num = q.front().first;
                int time = q.front().second;
                q.pop();
                for(auto i: adj[num])
                {
                    int infoTime = time + info[num];
                    ans = max(ans, infoTime);
                    if(info[i] != 0) q.push({i, infoTime});
                }
            }
        }
        return ans;
    }
};