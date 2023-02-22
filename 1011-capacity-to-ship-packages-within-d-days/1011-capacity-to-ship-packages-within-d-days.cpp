class Solution {
public:
    bool isValid(int mid, vector<int>& weights, int days)
    {
        int n=weights.size();
        int ct=1, sum=0;
        for(int i=0; i<n; i++)
        {
            sum+=weights[i];
            if(sum>mid)
            {
                ct++;
                sum=weights[i];
            }
        }
        return ct<=days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n=weights.size(), s=weights[0], e=0, ans=weights[0];
        for(int i: weights) s=max(s, i), e+=i;
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