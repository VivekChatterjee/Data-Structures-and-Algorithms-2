class Solution {
public:
    bool canFinish(int v, vector<vector<int>>& pre) {
        vector<int>adj[v];
        for(auto i: pre)
        {
            adj[i[1]].push_back(i[0]);
        }
        vector<int>indig(v);
        for(int i=0; i<v; i++)
        {
            for(auto num: adj[i])
            indig[num]++;
        }
        queue<int>q;
        for(int i=0; i<v; i++)
        {
            if(indig[i] == 0) q.push(i);
        }
        int count = 0;
        while(!q.empty())
        {
            int f = q.front();
            q.pop();
            count++;
            for(auto i: adj[f])
            {
                indig[i]--;
                if(indig[i] == 0) q.push(i);
            }
        }
        return (count == v);
    }
};