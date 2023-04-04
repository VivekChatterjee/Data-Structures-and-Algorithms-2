class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int n=nums.size();
        vector<int>rightMin(n, INT_MAX);
        rightMin[n-1]=nums[n-1];
        for(int i=n-2; i>=0; i--)
        {
            rightMin[i]=min(rightMin[i+1], nums[i]);
        }
        int ans=n-1, leftMax=INT_MIN;
        for(int i=0; i<n-1; i++)
        {
            leftMax=max(leftMax, nums[i]);
            if(leftMax<=rightMin[i+1])
            {
                ans=min(ans, i+1);
            }
        }
        return ans;
    }
};