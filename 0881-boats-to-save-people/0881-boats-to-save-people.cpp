class Solution {
public:
    int numRescueBoats(vector<int>& nums, int limit) {
        int n=nums.size();
        sort(nums.begin(), nums.end());
        int i=0, j=n-1, ans=0;
        while(i<=j)
        {
            if(nums[i]+nums[j]<=limit)
            {
                ans++;
                i++;
                j--;
            }
            else
            {
                ans++;
                j--;
            }
        }
        return ans;
    }
};