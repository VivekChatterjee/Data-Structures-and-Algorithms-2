class Solution {
public:
    int lines(int i, int j, vector<int>& s, vector<int>& t, vector<vector<int>>&dp)
    {
        int n=s.size(), nn=t.size();
        if(i==n || j==nn) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==t[j]) return dp[i][j] = 1+lines(i+1, j+1, s, t, dp);
        return dp[i][j]=max(lines(i+1, j, s, t, dp), lines(i, j+1, s, t, dp));
    }
    int maxUncrossedLines(vector<int>& s, vector<int>& t) {
        int n=s.size(), nn=t.size();
        vector<vector<int>>dp(n, vector<int>(nn, -1));
        return lines(0, 0, s, t, dp);
    }
};