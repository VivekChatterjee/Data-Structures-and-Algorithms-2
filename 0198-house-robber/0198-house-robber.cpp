class Solution {
public:
    int robIt(int i, vector<int>& nums, vector<int>& dp)
    {
        int n = nums.size();
        if(i >= n) return 0;
        if(dp[i] != -1) return dp[i];
        int dont = 0, take = 0;
        dont += robIt(i+1, nums, dp);
        take = nums[i] + robIt(i+2, nums, dp);
        return dp[i] = max(dont, take);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,-1);
        return robIt(0, nums, dp);
    }
};