class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int n=nums.size();
        int f=0, l=0, s=0, e=n-1;
        bool neg=0, pos=0;
        // for negative
        while(s<=e)
        {
            int mid=s+(e-s)/2;
            if(nums[mid]>=0)
            {
                e=mid-1;
            }
            else
            {
                neg=1;
                f=mid;
                s=mid+1;
            }
        }
        // for positive
        s=0, e=n-1;
        while(s<=e)
        {
            int mid=s+(e-s)/2;
            if(nums[mid]<=0)
            {
                s=mid+1;
            }
            else
            {
                pos=1;
                l=mid;
                e=mid-1;
            }
        }
        if(neg) f=f+1;
        if(pos) l=n-l;
        return max(f, l);
    }
};