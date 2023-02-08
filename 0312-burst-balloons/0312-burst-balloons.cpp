class Solution {
public:
    int balloons(int i, int j, vector<int>&nums, vector<vector<int>>&dp)
    {
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int ans=INT_MIN;
        for(int k=i; k<=j; k++)
        {
            int curCost=nums[i-1]*nums[k]*nums[j+1]
                +balloons(i, k-1, nums, dp)+balloons(k+1, j, nums, dp);
            ans=max(ans, curCost);            
        }
        return dp[i][j]=ans;
    }
    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(), 1);
        vector<vector<int>>dp(n+2, vector<int>(n+2, -1));
        return balloons(1, n, nums, dp);
    }
};