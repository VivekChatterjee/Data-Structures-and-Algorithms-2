#define ll long long
class Solution {
public:
    bool isValid(ll mid, vector<int>&time, int t)
    {
        ll cur=0;
        for(int i: time)
        {
            cur+=(mid/i);
            if(cur>=t) return 1;
        }
        return 0;
    }
    long long minimumTime(vector<int>& time, int t) {
        ll s=1, e=(ll)time[0]*t, ans=-1;
        while(s<=e)
        {
            ll mid=s+(e-s)/2;
            if(isValid(mid, time, t))
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