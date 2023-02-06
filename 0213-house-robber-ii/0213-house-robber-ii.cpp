class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n == 1) return nums[0];
        vector<int>dp(n), dp2(n);
        dp[0]=nums[0];
        for(int i=1; i<n-1; i++)
        {
            if(i==1) dp[i]=max(dp[i-1], nums[i]);
            else dp[i]=max(dp[i-2]+nums[i], dp[i-1]);
        }
        dp2[0]=0;
        for(int i=1; i<n; i++)
        {
            if(i==1) dp2[i]=max(dp2[i-1], nums[i]);
            else dp2[i]=max(dp2[i-2]+nums[i], dp2[i-1]);
        }
        return max(dp[n-2], dp2[n-1]);
    }
};