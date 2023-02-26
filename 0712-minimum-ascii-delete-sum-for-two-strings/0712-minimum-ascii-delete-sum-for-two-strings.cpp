class Solution {
public:
    int lcs(int i, int j, string &s, string &t, vector<vector<int>>&dp)
    {
        int n=s.size(), nn=t.size();
        if(i==n || j==nn) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==t[j])
        {
            return dp[i][j]=(int)s[i]+lcs(i+1, j+1, s, t, dp);
        }
        else
        {
            return dp[i][j]=max(lcs(i+1, j, s, t, dp), lcs(i, j+1, s, t, dp));
        }
    }
    int minimumDeleteSum(string s, string t) {
        int n=s.size(), nn=t.size(), ss=0, st=0;
        for(char c: s) ss+=(int)c;
        for(char c: t) st+=(int)c;
        vector<vector<int>>dp(n, vector<int>(nn, -1));
        int lc=lcs(0, 0, s, t, dp);
        return (ss-lc)+(st-lc);
    }
};