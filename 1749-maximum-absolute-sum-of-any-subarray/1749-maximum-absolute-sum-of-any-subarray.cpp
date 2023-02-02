class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n=nums.size();
        int maxSum=0, minSum=0, ans=abs(nums[0]);
        for(int i=0; i<n; i++)
        {
            maxSum+=nums[i];
            minSum+=nums[i];
            if(maxSum<0)
            {
                maxSum=0;
            }
            if(minSum>0)
            {
                minSum=0;
            }
            ans=max(ans, max(abs(maxSum), abs(minSum)));
        }
        return ans;
    }
};