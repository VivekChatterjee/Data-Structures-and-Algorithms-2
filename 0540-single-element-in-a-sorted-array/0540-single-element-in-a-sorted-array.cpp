class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        int s=0, e=n-1;
        while(s<=e)
        {
            int mid=s+(e-s)/2;
            int next=(mid+1<n)? nums[mid+1]:INT_MAX;
            int prev=(mid-1>=0)? nums[mid-1]:INT_MIN;
            if(nums[mid]!=prev && nums[mid]!=next) return nums[mid];
            else if(nums[mid]==prev)
            {
                if(mid%2) s=mid+1;
                else e=mid-1;
            }
            else
            {
                if(mid%2) e=mid-1;
                else s=mid+1;
            }
        }
        return -1;
    }
};