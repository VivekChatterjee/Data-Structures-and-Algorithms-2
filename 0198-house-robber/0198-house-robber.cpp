class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n);
        dp[0]=nums[0];
        for(int i=1; i<n; i++)
        {
            if(i == 1) dp[i]=max(dp[i-1], nums[i]);
            else dp[i]=max(dp[i-2]+nums[i], dp[i-1]);
        }
        return dp[n-1];
    }
};