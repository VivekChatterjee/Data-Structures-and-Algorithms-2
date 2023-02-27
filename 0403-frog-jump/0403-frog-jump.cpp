class Solution {
public:
    bool cross(int i, int k, vector<int>&s, unordered_map<int, int>&m, map<int, map<int, int>>&dp)
    {
        int n=s.size();
        if(!m.count(i)) return 0;
        if(i==s[n-1]) return 1;
        if(dp.count(i) && dp[i].count(k)) return dp[i][k];
        bool ans=0;
        for(int j=-1; j<=1; j++)
        {
            int cur=i+k+j;
            if(cur>i)
            {
                ans|=cross(cur, k+j, s, m, dp);
            }
        }
        return dp[i][k]=ans;
    }
    bool canCross(vector<int>& s) {
        unordered_map<int, int>m;
        map<int, map<int, int>>dp;
        for(int i: s) m[i]=1;
        return cross(1, 1, s, m, dp);
    }
};