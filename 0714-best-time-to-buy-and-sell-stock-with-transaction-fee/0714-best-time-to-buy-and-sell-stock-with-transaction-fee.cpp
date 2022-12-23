class Solution {
public:
    int f;
    int profit(bool buy, int cur, vector<int>&prices, vector<vector<int>>&dp)
    {
        int n = prices.size();
        if(cur >= n) return 0;
        int dont = 0, sell = 0;
        if(dp[cur][buy] != -1) return dp[cur][buy];
        // neithor buy nor sell here
        dont = 0 + profit(buy, cur+1, prices, dp);
        if(!buy)
        {  
            // buy here
            sell = -prices[cur] + profit(true, cur+1, prices, dp);
        }
        else
        {   
            // sell here
            sell = (prices[cur] - f) + profit(false, cur+1, prices, dp);
        }
        return dp[cur][buy] = max(sell, dont);
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size(); f = fee;
        vector<vector<int>>dp(n, vector<int>(2, -1));
        return profit(0, 0, prices, dp);
    }
};