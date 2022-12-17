class Solution {
public:
    vector<int> findOrder(int v, vector<vector<int>>& pre) {
        vector<int>adj[v], ans;
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
        while(!q.empty())
        {
            int f = q.front();
            q.pop();
            ans.push_back(f);
            for(auto i: adj[f])
            {
                indig[i]--;
                if(indig[i] == 0) q.push(i);
            }
        }
        if (ans.size() < v) return {};
        else return ans;
    }
};