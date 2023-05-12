#define ll long long int
class Solution {
public:
    ll points(int i, vector<vector<int>>&  q, vector<ll>&dp)
    {
        int n=q.size();
        if(i>=n) return 0;
        if(dp[i]!=-1) return dp[i];
        ll take=0, dont=0;
        dont+=points(i+1, q, dp);
        take=1LL*q[i][0]+points(i+q[i][1]+1, q, dp);
        return dp[i]=max(dont, take);
    }
    long long mostPoints(vector<vector<int>>&  q) {
        vector<ll>dp(q.size(), -1);
        return points(0, q, dp);
    }
};