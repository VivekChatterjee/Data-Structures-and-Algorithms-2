class Solution {
public:
    int robIt(int i, vector<int>& nums, vector<int>& dp)
    {
        int n = nums.size();
        if(i >= n) return 0;
        if(dp[i] != -1) return dp[i];
        int take = 0, dont = 0;
        dont = 0 + robIt(i+1, nums, dp);
        take = nums[i] + robIt(i+2, nums, dp);
        return dp[i] = max(dont, take);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        vector<int>dp(n, -1);
        int ans = robIt(1, nums, dp);
        nums.pop_back();
        vector<int>dp2(n, -1);
        ans = max(ans, robIt(0, nums, dp2)); 
        return ans;
    }
};