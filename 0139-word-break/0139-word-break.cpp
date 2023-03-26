class Solution {
public:
    bool breakWord(int i, int len, string &s, unordered_map<string, int>&m,             vector<vector<int>>&dp)
    {
        int n=s.size();
        if(i==n)
        {
            return n==len;
        }
        if(dp[i][len] != -1)
        {
         return dp[i][len];
        }
        string cur="";
        bool pos=0;
        for(int k=i; k<n; k++)
        {
            cur+=s[k];
            if(m.count(cur))
            {
                len+=cur.size();
                pos|=breakWord(k+1, len, s, m, dp);
                len-=cur.size();
            }
            if(pos) return 1;
        }
        return dp[i][len]=pos;
    }
    bool wordBreak(string s, vector<string>& w) {
        int n=s.size();
        unordered_map<string, int>m;
        for(auto &i: w) m[i]++;
        vector<vector<int>>dp(n+1, vector<int>(n+1, -1));
        return breakWord(0, 0, s, m, dp);
    }
};