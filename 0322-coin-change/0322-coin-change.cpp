class Solution {
public:
    int coin(int i, vector<int>&coins, int amount, vector<int>&dp)
    {
        int n=coins.size();
        if(amount==0) return 0;
        if(dp[amount] != -1) return dp[amount];
        int ans=1e7;
        for(auto it: coins)
        {
            if(amount-it>=0)
            ans=min(ans, coin(i, coins, amount-it, dp)+1);
        }
        return dp[amount]=ans;
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<int>dp(amount+1, -1);
        int ans=coin(0, coins, amount, dp);
        return (ans >= 1e7)? -1 : ans;
    }
};