class Solution {
public:
    int minDistance(string s, string t) {
        int n=s.size(), n2=t.size();
        vector<vector<int>>dp(n+1, vector<int>(n2+1));
        for(int i=1; i<=n; i++) dp[i][0]=i;
        for(int j=1; j<=n2; j++) dp[0][j]=j;
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n2; j++)
            {
                if(s[i-1]==t[j-1]) dp[i][j]=dp[i-1][j-1];
                else
                {
                    // del, rep, ins
                    int mini=1+min({dp[i-1][j], dp[i-1][j-1], dp[i][j-1]});
                    dp[i][j]=mini;
                }
            }
        }
        return dp[n][n2];
    }
};