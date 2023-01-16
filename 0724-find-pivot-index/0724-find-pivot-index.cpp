class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int rSum=0;
        for(int i: nums) rSum+=i;
        int lSum=0, n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(lSum == (rSum-lSum-nums[i])) return i;
            lSum+=nums[i];
        }
        return -1;
    }
};