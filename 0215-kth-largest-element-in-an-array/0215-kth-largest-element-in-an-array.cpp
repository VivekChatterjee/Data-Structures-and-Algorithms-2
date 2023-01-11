class Solution {
public:
    int isValid(int mid, vector<int>&nums)
    {
        int c=0;
        for(int i: nums) if(i>=mid) c++;
        return c;
    }
    int findKthLargest(vector<int>& nums, int k) {
        int n=nums.size();
        int mini=INT_MAX, maxi=INT_MIN;
        unordered_map<int, int>m;
        for(int i: nums) mini=min(mini, i), maxi=max(maxi, i), m[i]++;
        int s=mini, e=maxi;
        int ans=-1;
        while(s<=e)
        {
            int mid=s+(e-s)/2;
            int n=isValid(mid, nums);
            if(n>=k)
            {
                if(m.count(mid)) ans=mid;
                s=mid+1;
            }
            else e=mid-1;
        }
        return ans;
    }
};