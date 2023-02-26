class Solution {
public:
    int distance(int i, int j, string &s, string &t, vector<vector<int>>&dp)
    {
        int n=s.size(), nn=t.size();
        if(i==n && j==nn) return 0;
        if(i==n) return nn-j;
        if(j==nn) return n-i;
        if(dp[i][j]!=-1) return dp[i][j];
        int del=1e8, ins=1e8, rep=1e8;
        int ans=1e8;
        if(s[i]==t[j]) ans=0+distance(i+1, j+1, s, t, dp);
        else
        {
            del=1+distance(i+1, j, s, t, dp);
            ins=1+distance(i, j+1, s, t, dp);
            rep=1+distance(i+1, j+1, s, t, dp);
        }
        ans=min({ans, del, ins, rep});
        return dp[i][j]=ans;
    }
    int minDistance(string s, string t) {
        int n=s.size(), nn=t.size();
        vector<vector<int>>dp(n, vector<int>(nn, -1));
        return distance(0, 0, s, t, dp);
    }
};