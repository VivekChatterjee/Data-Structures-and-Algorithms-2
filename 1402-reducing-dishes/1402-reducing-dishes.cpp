class Solution {
public:
    int satisfy(int i, int time, vector<int>&s, vector<vector<int>>&dp)
    {
        int n=s.size();
        if(i==n) return 0;
        if(dp[i][time]!=-1) return dp[i][time];
        int dont=0, take=0;
        dont=0+satisfy(i+1, time, s, dp);
        take=s[i]*time+satisfy(i+1, time+1, s, dp);
        return dp[i][time]=max(dont, take);
    }
    int maxSatisfaction(vector<int>& s) 
    {
        sort(s.begin(), s.end());
        int n=s.size();
        vector<vector<int>>dp(n, vector<int>(n+1, -1));
        return satisfy(0, 1, s, dp);        
    }
};