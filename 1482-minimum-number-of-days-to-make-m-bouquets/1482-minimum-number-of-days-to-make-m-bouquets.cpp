#define ll long long int
class Solution {
public:
    bool isValid(int mid, vector<int>&bloom, int m, int k)
    {
        int n=bloom.size();
        int bouq=0, adj=0;
        for(int i: bloom)
        {
            if(i <= mid) 
            {
                adj++;
                if(adj == k)
                {
                    bouq++;
                    adj=0;
                }
            }
            else adj=0;
        }
        return bouq>=m;
    }
    int minDays(vector<int>& bloom, int m, int k) {
        int s=INT_MAX,e=INT_MIN;
        for(int i: bloom) s=min(s, i), e=max(e, i);
        int ans=-1;
        while(s<=e)
        {
            int mid=s+(e-s)/2;
            if(isValid(mid, bloom, m, k))
            {
                ans=mid;
                e=mid-1;
            }
            else s=mid+1;
        }
        return ans;
    }
};