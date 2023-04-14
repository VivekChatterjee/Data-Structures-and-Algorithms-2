class Solution {
public:
    int pal(int i, int j, string &s, vector<vector<int>>&dp)
    {
        int n=s.size();
        if(i>j) return 0;
        if(i==j) return 1;
        if(dp[i][j]!=-1) return dp[i][j];
        int take=0, dont=0;
        if(s[i]==s[j])
        {
            take=2+pal(i+1, j-1, s, dp);
        }
        else
        {
            dont+=max(pal(i+1, j, s, dp), pal(i, j-1, s, dp));
        }
        return dp[i][j]=max(take, dont);
    }
    int longestPalindromeSubseq(string &s) {
        int n=s.size(); 
        vector<vector<int>>dp(n, vector<int>(n, -1));
        return pal(0, n-1, s, dp);
    }
};