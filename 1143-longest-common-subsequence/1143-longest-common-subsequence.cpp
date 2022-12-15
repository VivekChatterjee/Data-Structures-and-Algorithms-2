class Solution {
public:
    int lcs(int i, int j, string &t1, string &t2, vector<vector<int>> &dp)
    {
        int n1 = t1.size();
        int n2 = t2.size();
        if(i < 0 || j < 0) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(t1[i] == t2[j])
            return dp[i][j] = 1 + lcs(i-1, j-1, t1, t2, dp);
        else
            return dp[i][j] = max(lcs(i-1, j, t1, t2, dp), lcs(i, j-1, t1, t2, dp));
    }
    int longestCommonSubsequence(string t1, string t2) {
        vector<vector<int>> dp(t1.size(), vector<int>(t2.size(), -1));
        return lcs(t1.size()-1, t2.size()-1, t1, t2, dp);
    }
};