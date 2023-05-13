class Solution {
public:
    int K = 1e9+7;
    int good(int low, int high, int zero, int one, int ans, vector<int> &dp)
    {
        if(dp[ans] != -1) return dp[ans];
        int res=0;
        if(ans >= low && ans <= high) res+=1;
        if(ans + zero <= high)
        res+= good(low, high, zero, one, ans+zero, dp) % K;
        if(ans + one <= high)
        res+= good(low, high, zero, one, ans+one, dp) % K;
        return dp[ans] = res % K;
    }
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int>dp(high+1, -1);
        return good(low, high, zero, one, 0, dp);
    }
};