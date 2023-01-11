class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int l=0, h=n-1;
        int ans=INT_MAX;
        while(l<=h)
        {
            int mid=l+(h-l)/2;
            ans=min(ans, nums[mid]);
            if(nums[h]<nums[mid])
            {
                l=mid+1;
            }
            else h=mid-1;
        }
        return ans;
    }
};