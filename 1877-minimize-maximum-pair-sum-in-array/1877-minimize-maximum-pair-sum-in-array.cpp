class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int i=0, n=nums.size(), j=n-1, ans=INT_MIN;
        while(i<j)
        {
            ans=max(ans, nums[i]+nums[j]);
            i++;
            j--;
        }
        return ans;
    }
};