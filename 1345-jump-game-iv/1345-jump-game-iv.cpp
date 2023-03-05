class Solution {
public:
    int minJumps(vector<int>& arr) {
        unordered_map<int, vector<int>>m;
        int n=arr.size();
        if(n==1) return 0;
        for(int i=0; i<n; i++)
        {
            m[arr[i]].push_back(i);
        }
        queue<int>q;
        q.push(0);
        vector<int>vis(n);
        vis[0]=1;
        int ans=0;
        while(!q.empty())
        {
            int sz=q.size();
            for(int i=0; i<sz; i++)
            {
                int node=q.front();
                q.pop();
                if(node==n-1) return ans;
                if(node+1<n && !vis[node+1])
                {
                    q.push(node+1);
                    vis[node+1]=1;
                }
                if(node-1>=0 && !vis[node-1])
                {
                    q.push(node-1);
                    vis[node-1]=1;
                }
                for(auto it: m[arr[node]])
                {
                    if(!vis[it])
                    {
                        vis[it]=1;
                        q.push(it);
                    }
                }
                m[arr[node]].clear();
            }
            ans++;
        }
        return -1;
    }
};