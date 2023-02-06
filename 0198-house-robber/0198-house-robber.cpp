class Solution {
public:
    int robIt(int i, vector<int>&nums, vector<int>&dp)
    {
        int n=nums.size();
        if(i>=n) return 0;
        if(dp[i] != -1) return dp[i];
        int take=0, dont=0;
        dont=0+robIt(i+1, nums, dp);
        take=nums[i]+robIt(i+2, nums, dp);
        return dp[i]=max(take, dont);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n, -1);
        return robIt(0, nums, dp);
    }
};