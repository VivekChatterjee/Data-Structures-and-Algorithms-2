class Solution {
public:
    bool canFinish(int num, vector<vector<int>>& pre) {
        vector<int>ind(num);
        vector<int>adj[num];
        for(auto &it: pre)
        {
            adj[it[1]].push_back(it[0]);
            ind[it[0]]++;
        }
        queue<int>q;
        for(int i=0; i<num; i++)
        {
            if(ind[i] == 0)
            {
                q.push(i);
            }
        }
        int ct=0;
        while(!q.empty())
        {
            int front=q.front();
            q.pop();
            ct++;
            for(auto &it: adj[front])
            {
                ind[it]--;
                if(ind[it] == 0)
                {
                    q.push(it);
                }
            }
        }
        return ct==num;
        
    }
};