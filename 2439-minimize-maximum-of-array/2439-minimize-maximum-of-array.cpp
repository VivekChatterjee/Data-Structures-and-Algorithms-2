#define ll long long
class Solution {
public:
    bool isValid(int mid, vector<ll>v)
    {
        int n=v.size();
        for(int i=n-1; i>0; i--)
        {
            if(v[i]>mid)
            {
                ll chances=v[i]-mid;
                v[i]=mid;
                v[i-1]+=chances;
            }
        }
        return v[0]<=mid;
    }
    int minimizeArrayValue(vector<int>& nums) {
        int n=nums.size();
        int s=nums[0], e=INT_MIN;
        int ans=e;
        vector<ll>v;
        for(int i: nums)
        {
            v.push_back(i*1LL);
            e=max(e, i);
        }
        while(s<=e)
        {
            int mid=s+(e-s)/2;
            if(isValid(mid, v))
            {
                ans=mid;
                e=mid-1;
            }
            else
            {
                s=mid+1;
            }
        }
        return ans;
    }
};