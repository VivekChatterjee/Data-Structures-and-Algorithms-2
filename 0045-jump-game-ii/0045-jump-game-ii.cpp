class Solution {
public:
    int jumpGame(int i, vector<int>&nums, vector<int>&dp)
    {
        int n=nums.size();
        if(i==n-1) return 0;
        if(i>=n || nums[i]==0) return 1e8;
        if(dp[i]!=-1) return dp[i];
        int total=nums[i], ans=1e8;
        for(int j=1;j<=total;j++)
        {
            int cur=1+jumpGame(i+j, nums, dp);
            ans=min(ans, cur);
        }
        return dp[i]=ans;
    }
    int jump(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n, -1);
        return jumpGame(0, nums, dp);
    }
};