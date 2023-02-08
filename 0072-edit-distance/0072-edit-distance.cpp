class Solution {
public:
    int dist(int i, int j, string s, string t, vector<vector<int>>&dp)
    {
        int n=s.size(), n2=t.size();
        if(i==n) return n2-j;
        if(j==n2) return n-i;
        if(dp[i][j]!=-1) return dp[i][j];
        int ins=0, rep=0, del=0;
        if(s[i]==t[j]) return dp[i][j]=0+dist(i+1, j+1, s, t, dp);
        else
        {
            ins=1+dist(i, j+1, s, t, dp);
            rep=1+dist(i+1, j+1, s, t, dp);
            del=1+dist(i+1, j, s, t, dp);
            return dp[i][j]=min(ins, min(rep, del));
        }
    }
    int minDistance(string word1, string word2) {
        int n=word1.size(), n2=word2.size();
        vector<vector<int>>dp(n+1, vector<int>(n2+1, -1));
        return dist(0, 0, word1, word2, dp);
    }
};