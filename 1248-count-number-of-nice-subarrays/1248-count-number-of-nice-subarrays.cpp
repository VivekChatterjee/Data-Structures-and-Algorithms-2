class Solution {
public:
    int niceAtmostK(vector<int>&nums, int k)
    {
        int ct=0, i=0;
        for(int j=0; j<nums.size(); j++)
        {
            if(nums[j] % 2) k--;
            while(k<0)
            {
                if(nums[i] % 2) k++;
                i++;
            }
            ct+=j-i+1;
        }
        return ct;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return niceAtmostK(nums, k) - niceAtmostK(nums, k-1);
    }
};