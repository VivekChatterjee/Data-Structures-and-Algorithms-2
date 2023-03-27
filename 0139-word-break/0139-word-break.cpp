class Solution {
public:
    bool breakWord(int i, string &s, unordered_map<string, int>&m,                       vector<int>&dp)
    {
        int n=s.size();
        if(i==n) return 1;
        if(dp[i] != -1) return dp[i];
        for(int k=i; k<n; k++)
        {
            if(m.count(s.substr(i, k-i+1)) && breakWord(k+1, s, m, dp))
                return dp[i]=1;
        }
        return dp[i]=0;
    }
    bool wordBreak(string s, vector<string>& w) {
        int n=s.size();
        unordered_map<string, int>m;
        for(auto &i: w) m[i]++;
        vector<int>dp(n+1, -1);
        return breakWord(0, s, m, dp);
    }
};