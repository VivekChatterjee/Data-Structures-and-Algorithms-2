class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        vector<int>adj[n], in(n), ans;
        for(auto i: pre)
        {
            adj[i[1]].push_back(i[0]);
            in[i[0]]++;
        }
        queue<int>q;
        for(int i=0; i<n; i++)
        {
            if(in[i] == 0) q.push(i);
        }
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            ans.push_back(node);
            for(auto it: adj[node])
            {
                in[it]--;
                if(in[it] == 0) q.push(it);
            }
        }
        if(ans.size() != n) ans.clear();
        return ans;
    }
};