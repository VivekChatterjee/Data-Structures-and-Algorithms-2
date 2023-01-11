#define ll long long int
class Solution {
public:
    int mySqrt(int x) {
        if(!x) return x;
        int s=1, e=x;
        int ans=-1;
        while(s<=e)
        {
            ll mid=s+(e-s)/2;
            if(mid*mid <= x)
            {
                ans=mid;
                s=mid+1;
            }
            else e=mid-1;
        }
        return ans;
    }
};