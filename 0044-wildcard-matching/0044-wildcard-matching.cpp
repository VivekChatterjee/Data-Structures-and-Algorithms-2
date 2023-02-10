class Solution {
public:
    bool match(int i, int j, string &s, string &p, vector<vector<int>>&dp)
    {
        int n=s.size(), np=p.size();
        if(i==n and j==np) return 1; //both ends
        else if(i==n)
        {
            return (p[j]=='*' and match(i, j+1, s, p, dp));
        }
        else if(j==np) return dp[i][j]=0; //only pattern ends
        if(dp[i][j]!=-1) return dp[i][j];
        //single character matches
        if(p[j]=='?' or p[j]==s[i]) return dp[i][j]=match(i+1,j+1, s, p, dp);
        if(p[j]=='*')
        {
            return dp[i][j]=(match(i, j+1, s, p, dp) || match(i+1, j, s, p, dp));
        }
        return dp[i][j]=0;
    }
    bool isMatch(string s, string p) 
    {
        int n=s.size(), np=p.size();
        vector<vector<int>>dp(n+1, vector<int>(np+1, -1));
        return match(0, 0, s, p, dp);
    }
};