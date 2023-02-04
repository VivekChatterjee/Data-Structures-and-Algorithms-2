class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        int ans=1;
        vector<int>dp(n, 1);
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<i; j++)
            {
                if(nums[j]<nums[i])
                {
                    dp[i]=max(dp[j]+1, dp[i]);
                    ans=max(ans, dp[i]);
                }
            }
        }
        return ans;
    }
};