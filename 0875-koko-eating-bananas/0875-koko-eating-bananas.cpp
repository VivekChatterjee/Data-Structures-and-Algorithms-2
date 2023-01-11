#define ll long long int
class Solution {
public:
    bool isValid(int mid, vector<int>&piles, int h)
    {
        ll n=0;
        for(int i: piles)
        {
            if(mid<i)
            {
                if(i%mid != 0)
                {
                    n+=((ll)i/mid)+1;
                }
                else n+=((ll)i/mid);
            }
            else
            {
                n++;
            }
        }
        return n<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int s=1, e=INT_MIN;
        for(int i: piles) e=max(e, i);
        int ans=-1;
        while(s<=e)
        {
            int mid=s+(e-s)/2;
            if(isValid(mid, piles, h))
            {
                ans=mid;
                e=mid-1;
            }
            else s=mid+1;
        }
        return ans;
    }
};