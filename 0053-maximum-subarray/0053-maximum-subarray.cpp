class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size(), start=0, end=0;
        int ans=nums[0];
        int maxSum=0;
        for(int i=0; i<n; i++)
        {
            maxSum+=nums[i];
            if(maxSum>ans)
            {
                ans=maxSum;
                end=i;
            }
            if(maxSum<0)
            {
                maxSum=0;
                start=i+1;
            }
        }
        return ans;
    }
};