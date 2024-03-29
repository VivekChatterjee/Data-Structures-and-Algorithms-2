class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int>vis(n+1);
        for(auto i: trust)
        {
            vis[i[1]]++;
            vis[i[0]]--;
        }
        for(int i=1; i<=n; i++)
        {
            if(vis[i] == n-1) return i;
        }
        return -1;
    }
};