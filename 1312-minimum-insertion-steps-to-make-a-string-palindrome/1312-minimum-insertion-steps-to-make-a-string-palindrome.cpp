class Solution {
public:
    int ins(int i, int j, string &s, vector<vector<int>>&dp)
    {
        int n=s.size();
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int take=1e8, takeLeft=1e8, takeRight=1e8;
        if(s[i]==s[j])
        {
            take=0+ins(i+1, j-1, s, dp);
        }
        else
        {
            takeLeft=1+ins(i+1, j, s, dp);
            takeRight=1+ins(i, j-1, s, dp);
        }
        return dp[i][j]=min({take, takeLeft, takeRight});
    }
    int minInsertions(string &s) {
        int n=s.size();
        vector<vector<int>>dp(n, vector<int>(n, -1));
        return ins(0, n-1, s, dp);
    }
};