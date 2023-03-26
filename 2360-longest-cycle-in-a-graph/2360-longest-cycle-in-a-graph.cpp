class Solution {
public:
    int ans=0;
    void isCycle(int node, vector<int>& edges, vector<int>&vis)
    {
        vis[node]=2;
        int to=edges[node];
        if(to != -1)
        {
            if(vis[to] == 2)
            {
                int cur=to, len=0;
                do{
                    len++;
                    vis[cur]=1;
                    cur = edges[cur];
                }while(cur != to);
                ans=max(ans, len);
            }
            else if(!vis[to])
            {
                isCycle(to, edges, vis);
            }
        }
        vis[node]=1;
    }
    int longestCycle(vector<int>& edges) {
        int n=edges.size();
        vector<int>vis(n);
        for(int i=0; i<n; i++)
        {
            if(!vis[i])
            {
                isCycle(i, edges, vis);
            }
        }
        if(!ans) return -1;
        return ans;
    }
};