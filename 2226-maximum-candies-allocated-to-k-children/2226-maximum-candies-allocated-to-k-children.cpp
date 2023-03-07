#define ll long long
class Solution {
public:
    bool isValid(ll mid, vector<int>&c, ll k)
    {
        ll ct=0;
        for(int i: c)
        {
            ct+=((ll)i/mid);
        }
        return ct>=k;
    }
    int maximumCandies(vector<int>& c, long long k) {
        ll maxi=INT_MIN, n=c.size();
        for(int i: c) 
        {
            maxi=max(maxi, (ll)i);
        }
        ll s=1, e=maxi, ans=0;
        while(s<=e)
        {
            ll mid=s+(e-s)/2;
            if(isValid(mid, c, k))
            {
                ans=mid;
                s=mid+1;
            }
            else
            {
                e=mid-1;
            }
        }
        return ans;
    }
};