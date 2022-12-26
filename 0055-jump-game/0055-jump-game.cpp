class Solution {
public:
    bool jump(int i, vector<int>& nums, vector<int>& dp)
    {
        int n = nums.size();
        if(i >= n || (i < n-1 && nums[i] == 0)) return 0;
        else if(i == n-1) return 1;
        if(dp[i] != -1) return dp[i];
        int maxJump = nums[i];
        for(int j=1; j<=maxJump; j++)
        {
            if(jump(i+j, nums, dp)) return dp[i] = 1;
        }
        return dp[i] = 0;
    }
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return 1;
        vector<int>dp(n, -1);
        return jump(0, nums, dp);
    }
};