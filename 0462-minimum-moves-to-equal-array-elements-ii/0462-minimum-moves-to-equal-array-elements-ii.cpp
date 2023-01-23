class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(), nums.end());
        int ans=0;
        if(n%2 == 0)
        {
            int avg=nums[n/2], avg2=nums[n/2-1], a1=0, a2=0;
            for(int i: nums)
            {
                a1+=abs(i-avg);
                a2+=abs(i-avg2);
            }
            ans=min(a1, a2);
        }
        else
        {
            int avg=nums[n/2];            
            for(int i: nums)
            {
                ans+=abs(i-avg);
            }
            
        }
        return ans;
    }
};