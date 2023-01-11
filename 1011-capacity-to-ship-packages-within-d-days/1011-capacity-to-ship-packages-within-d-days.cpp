class Solution {
public:
    bool isValid(int mid, vector<int>& weights, int days)
    {
        int n=1, cur=0;
        for(int i: weights)
        {
            if(i>mid) return 0;
            cur+=i;
            if(cur>mid)
            {
                n++;
                cur=i;
            }
            if(n>days) return 0;
        }
        return n<=days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int s=INT_MAX, e=0;
        for(int i: weights) s=min(s, i) , e += i;
        int ans=-1;
        while(s<=e)
        {
            int mid=s+(e-s)/2;
            if(isValid(mid, weights, days))
            {
                ans=mid;
                e=mid-1;
            }
            else s=mid+1;
        }
        return ans;
    }
};