#define ll long long
class Solution {
public:
    ll opera(ll i, vector<ll>&pre, vector<int>&nums)
    {
        ll n=nums.size();
        ll ind=lower_bound(nums.begin(), nums.end(), i)-nums.begin();
        ll a=i*(ind) - pre[ind];
        ll b=(pre[n]-pre[ind]) - i*(n-ind);
        return a+b;
    }
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
        ll n=nums.size();
        sort(nums.begin(), nums.end());
        vector<ll>pre(n+1);
        pre[0]=0;
        for(int i=1; i<=n; i++)
        {
            pre[i]=pre[i-1]+nums[i-1];
        }
        vector<ll>ans;
        for(ll i: queries)
        {
            ans.push_back(opera(i, pre, nums));
        }
        return ans;
    }
};